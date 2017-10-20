#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<ctime>
#include<queue>
#include<set>
using namespace std;
const int INF = 0x3f3f3f3f, MAXN = 1000500, MAXM = 6000000;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

struct Edge
{
    int to, f, next;
    Edge(){ to = f = 0; next = -1; }
    Edge(int _to, int _f, int _next):to(_to), f(_f), next(_next){}
}edge[MAXM];

int e = 0, head[MAXN];
int cur[MAXN], h[MAXN], gap[MAXN];
int s, t, N;

void add(int u, int v, int f)
{
    edge[e] = Edge(v, f, head[u]);
    head[u] = e++;
    edge[e] = Edge(u, 0, head[v]);
    head[v] = e++;
}

bool bfs()
{
    memset(h, -1, sizeof(h));
    memset(gap, 0, sizeof(gap));
    queue<int> q;
    q.push(t);
    ++gap[h[t]=0];
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (h[v] == -1)
            {
                ++gap[h[v]=h[u]+1];
                q.push(v);
            }
        }
    }
    return ~h[s];
}

int dfs(int u, int surplus)
{
    if (u == t) return surplus;
    int flow = 0;
    for (int i = cur[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (h[u] == h[v]+1 && edge[i].f)
        {
            int nowFlow = dfs(v, min(surplus-flow, edge[i].f));
            edge[i].f -= nowFlow;
            edge[i^1].f += nowFlow;
            flow += nowFlow;
            if (flow == surplus)
            {
                cur[u] = i;
                return flow;
            }
        }
    }
    if (!--gap[h[u]]) h[s] = N+2;
    ++gap[++h[u]];
    cur[u] = head[u];
    return flow;
}

int sap()
{
    if (!bfs()) return 0;
    int flow = 0;
    memcpy(cur, head, sizeof(cur));
    while (h[s] < N+2)
        flow += dfs(s, INF);
    return flow;
}

int main()
{
    e = 0;
    memset(head, -1, sizeof(head));
    int n, m, sum = 0;
    scanf("%d%d", &n, &m);
    s = n*m; N = t = s+1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int value;
            scanf("%d", &value);
            sum += value;
            if ((i+j)&1) add(i*m+j, t, value);
            else
            {
                add(s, i*m+j, value);
                for (int k = 0; k < 4; k++)
                {
                    int xx = i+dx[k], yy = j+dy[k];
                    if (xx >= 0 && xx < n && yy >= 0 && yy < m)
                        add(i*m+j, xx*m+yy, INF);
                }
            }
        }
    printf("%d\n", sum-sap());
    return 0;
}



