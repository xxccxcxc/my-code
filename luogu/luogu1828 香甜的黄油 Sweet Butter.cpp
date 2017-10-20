#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue> 
using namespace std;
const int C = 550, N = 850, M = 1500, INF = 0x3f3f3f3f;
struct Edge
{
    int w, to, next;
}edge[M*2];
int e, head[N];
int c, n, m;
int pos[C];
void add1(int u, int v, int w)
{
    edge[e].w = w;
    edge[e].to = v;
    edge[e].next = head[u];
    head[u] = e++;
}
void add(int u, int v, int w)
{
    add1(u, v, w);
    add1(v, u, w);
}
int SPFA(int s)
{
    bool vis[N] = {0};
    queue<int> q;
    int f[N];
    memset(f, 0x3f, sizeof(f));
    vis[s] = true;
    q.push(s);
    f[s] = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (f[u] + edge[i].w < f[v])
            {
                f[v] = f[u] + edge[i].w;
                vis[v] = true;
                q.push(v);
            }
        }
        vis[u] = false;
    }
    int ret = 0;
    for (int i = 1; i <= c; i++)
        ret += f[pos[i]];
    return ret;
}
int main()
{
    memset(head, -1, sizeof(head));
    cin >> c >> n >> m;
    for (int i = 1; i <= c; i++)
        cin >> pos[i];
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    int ans = INF;
    for (int i = 1; i <= n; i++)
        ans = min(ans, SPFA(i));
    cout << ans << endl;
    return 0;
}

