#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
#define getchar() (S == T && (T = (S = BB) + fread(BB, 1, 1 << 15, stdin), S == T) ? EOF : *S++)
using namespace std;
char BB[1 << 15], *S = BB, *T =BB;
const int MAXN = 5050, MAXM = 50050, INF = 0x3f3f3f3f;
struct Edge
{
    int u;
    int v;
    int f;  //可增加的流量 
    int c;  //费用 
    int next;
}edge[MAXM << 2];
int n, m, s, t;
int e;
int head[MAXN];
int dis[MAXN], pre[MAXN];
bool vis[MAXN];
int read()
{
    char ch = getchar();int x = 0, f = 1;
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}
void addEdge(int u, int v, int f, int c)
{
    edge[e].u = u;
    edge[e].v = v;
    edge[e].f = f;
    edge[e].c = c;
    edge[e].next = head[u];
    head[u] = e++;
}
void add(int u, int v, int f, int c)  //加入正向和反向弧 
{
    addEdge(u, v, f, c);
    addEdge(v, u, 0, -c);
}
bool SPFA()
{
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    memset(dis, 0x3f, sizeof(dis));
    vis[s] = true;
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].v;
            if (edge[i].f && dis[v] > dis[u] + edge[i].c)
            {
                dis[v] = dis[u] + edge[i].c;
                pre[v] = i;
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return dis[t] != INF;
}
void MCMF(int &flow, int &cost)
{
    flow = cost = 0;
    while (SPFA())
    {
        int minFlow = INF;
        for (int i = pre[t]; ~i; i = pre[edge[i].u])
            minFlow = min(minFlow, edge[i].f);  //取最小容量增广 
        flow += minFlow;
        for (int i = pre[t]; ~i; i = pre[edge[i].u])
        {
            edge[i].f -= minFlow;
            edge[i ^ 1].f += minFlow;  //i^1为i的反向弧 
        }
        cost += dis[t] * minFlow;
    }
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++)
    {
        int u, v, f, c;
        scanf("%d%d%d%d", &u, &v, &f, &c);
        add(u, v, f, c);
    }
    int flow, cost;
    MCMF(flow, cost);
    printf("%d %d\n", flow, cost);
    return 0;
}

