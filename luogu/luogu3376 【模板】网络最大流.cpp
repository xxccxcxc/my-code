#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#define inf 0x7fffffff
#define getchar() (S == T && (T = (S = BB) + fread(BB, 1, 1 << 15, stdin), S == T) ? EOF : *S++)
char BB[1 << 15], *S = BB, *T = BB; // fast istream
using namespace std;

int n, m, s, t; // problem

int gap[202001], h[202001], cur[202001], pre[202001]; //sap

struct edge
{
    int to, next, w;
}e[1002001];int head[202001], top; //graph

int read() // fast instream
{
    char ch = getchar();int x = 0, f = 1;
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}

void add(int w, int v, int u)
{
    e[top].next = head[u]; e[top].to = v;
    e[top].w = w; head[u] = top++;
    
    e[top].next = head[v]; e[top].to = u;
    e[top].w = 0; head[v] = top++;
}


bool bfs() // bfs pretreatment height mark
{
    memset(gap, 0, sizeof(gap)); // gap[] for optimization
    memset(h, -1, sizeof(h)); // h[] for height mark
    
    gap[++h[t]]++; // add t
    queue<int>q; q.push(t);
    
    while(!q.empty())
    {
        int u = q.front();q.pop();  
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!(~h[v])) // mark height
            {
                q.push(v);
                gap[h[v] = h[u] + 1]++;
            }
        }
    }
    
    return ~h[s]; // if the start have not been marked, the flow can't work.
}

int augment(int s, int t) // augmentation operation 
{
    int flow = inf;
    for (int i = t; i != s; i = e[pre[i] ^ 1].to) // find the min added flow
        flow = min(flow, e[pre[i]].w);
    
    for (int i = t;i != s; i = e[pre[i]^1].to) // updata the edge
        e[pre[i]].w -= flow, e[pre[i]^1].w += flow;
    
    return flow; // return the flow
}

int isap()
{
    if(!bfs()) return 0; // bfs pretreatment height mark
    
    int u = s, maxflow = 0; // u is the now point
    for(int i = 1;i <= n; ++i) cur[i] = head[i]; // current edge optimization
    while(h[s] < n)
    {
        if(u == t) // augment the network
            maxflow += augment(s, t), u = s;
        
        bool not_find = true; // not_find means if the now point's surplus can be flow away
        
        for(int i = cur[u]; ~i; i = e[i].next) // propulsion
        {
            int v = e[i].to;
            if (h[v] + 1 == h[u] && e[i].w > 0)
            {
                not_find = false;
                cur[u] = i; // current edge optimization
                
                pre[v] = i; // record the augmentation way
                u = v;
                break;
            }
        }
        
        if(not_find) //relabel
        {
            int minn = n - 1;
            for (int i = head[u]; ~i; i = e[i].next)
                if (e[i].w > 0)
                    minn = min(minn, h[e[i].to]);
            
            if (!(--gap[h[u]])) break; // gap optimization
            gap[h[u] = minn + 1]++;
            cur[u] = head[u];
            if (u != s)
                u = e[pre[u] ^ 1].to; // return to the previous point
        }
    }
    
    return maxflow; // return the answer
}

void init() // initialize the graph
{
    memset(head, -1, sizeof(head)); top = 0;
    n = read(); m = read();
    s = read(); t = read();
    for(int i = 1;i <= m; ++i)
        add(read(), read(), read());
}

int main()
{
    init();
    printf("%d\n", isap());
    return 0;
}


