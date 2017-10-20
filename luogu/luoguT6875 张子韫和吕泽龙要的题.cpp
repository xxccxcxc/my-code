#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#define HL cout << "hello" << endl;
#define ZT system("pause");
using namespace std;
const int MAXN = 250, MAXM = 200000, INF = 0x3f3f3f3f;

struct Edge
{
    int to, f, next;
    Edge(){}
    Edge(int _to, int _f, int _next):to(_to), f(_f), next(_next){}
}edge[MAXM];

int e, head[MAXN], dis[MAXN];

void add(int u, int v, int f)
{
    edge[e] = Edge(v, f, head[u]);
    head[u] = e++;
    edge[e] = Edge(u, 0, head[v]);
    head[v] = e++;
}

bool bfs(int s, int t)
{
    memset(dis, 0, sizeof(dis));
    dis[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (edge[i].f && !dis[v])
            {
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }
    return dis[t];
}

int dfs(int u, int t, int now_flow)
{
    if (u == t) return now_flow;
    if (dis[u] >= dis[t]) return 0;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to, flow;
        if (edge[i].f && dis[v] == dis[u]+1 && (flow = dfs(v, t, min(now_flow, edge[i].f))))
        {
            edge[i].f -= flow;
            edge[i^1].f += flow;
            return flow;
        }
    }
    return 0;
}

int dinic(int s, int t)
{
    int max_flow = 0, flow;
    while (bfs(s, t))
    {
        while (flow = dfs(s, t, INF))
            max_flow += flow;
    }
    return max_flow;
}

int main()
{
    memset(head, -1, sizeof(head));
    int n, m, d[MAXN] = {0};
    scanf("%d%d", &n, &m);
    int s = 0, t = n+1, u, v, low[MAXM], high;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d%d", &u, &v, low+i, &high);
        d[u] -= low[i]; d[v] += low[i];
        add(u, v, high-low[i]);
    }
    for (int i = 1; i <= n; i++)
        if (d[i] > 0) add(s, i, d[i]);
        else if (d[i] < 0) add(i, t, -d[i]);
    dinic(s, t);
    bool ok = true;
    for (int i = head[s]; ~i; i = edge[i].next)
        if (edge[i].f)
        {
            ok = false;
            break;
        }
    if (!ok) printf("NO\n");
    else
    {
        printf("YES\n");
        for (int i = 0; i < m; i++)
            printf("%d\n", edge[i*2+1].f + low[i]);
    }
    return 0;
}


