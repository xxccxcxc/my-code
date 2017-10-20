#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 100050, M = 100050;
struct Edge
{
    int to, w, next;
}edge[M*4];
int e, head[N];
ll dis[N];
bool vis[N];
void add1(int u, int v, int w)
{
    edge[e].to = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
}
bool dfs(int u)
{
    vis[u] = true;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (dis[u] + edge[i].w < dis[v])
        {
            dis[v] = dis[u] + edge[i].w;
            if (vis[v] || dfs(v))
                return true;
        }
    }
    vis[u] = false;
    return false;
}
int main()
{
    memset(head, -1, sizeof(head));
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int opt, u, v;
        cin >> opt >> u >> v;
        switch (opt)
        {
            case 1: add1(u, v, 0); add1(v, u, 0); break;
            case 2: add1(u, v, -1); break;
            case 3: add1(v, u, 0); break;
            case 4: add1(v, u, -1); break;
            case 5: add1(u, v, 0); break;
        }
    }
    for (int i = n; i >= 1; i--)
        add1(0, i, -1);
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0; 
    if (dfs(0)) cout << -1 << endl;
    else
    {
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans -= dis[i];
        cout << ans << endl;
    }
    return 0;
}

