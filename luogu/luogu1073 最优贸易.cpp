#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue> 
using namespace std;
const int N = 100050, M = 500050;
struct Edge
{
    bool w;
    int to, next;
}edge[M*2];
int e, head[N];
int n, m, ans;
int price[N], f[N];
bool vis2[N];
void add1(int u, int v, int w)
{
    edge[e].w = w;
    edge[e].to = v;
    edge[e].next = head[u];
    head[u] = e++;
}
void add(int u, int v, bool p)
{
    add1(u, v, 1);
    add1(v, u, p);
}
int SPFA()
{
    bool vis[N] = {0};
    queue<int> q;
    memset(f, 0x3f, sizeof(f));
    vis[1] = true;
    q.push(1);
    f[1] = price[1];
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            if (!edge[i].w) continue;
            int v = edge[i].to;
            if (f[u] < f[v])
            {
                f[v] = min(f[u], price[v]);
                vis[v] = true;
                q.push(v);
            }
        }
        vis[u] = false;
    }
}
void dfs(int u)
{
    vis2[u] = true;
    ans = max(ans, price[u] - f[u]);
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (edge[i^1].w && !vis2[v])
            dfs(v);
    }
}
int main()
{
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> price[i];
    while (m--)
    {
        int u, v, p;
        cin >> u >> v >> p;
        add(u, v, (p == 2));
    }
    SPFA();
    dfs(n);
    cout << ans << endl;
    return 0;
}

