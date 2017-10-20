#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 150, M = 1050;
struct Edge
{
    int to, w, next;
}edge[M*4];
int e, head[N];
int T, n, m;
int dis[N];
bool vis[N];
void add1(int u, int v, int w)
{
    edge[e].to = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
}
void clear()
{
    e = 0;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
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
    cin >> T;
    while (T--)
    {
        clear();
        cin >> n >> m;
        while (m--)
        {
            int l, r, w;
            cin >> l >> r >> w;
            add1(l-1, r, w);
            add1(r, l-1, -w);
        }
        int s = n+1;
        dis[s] = 0;
        for (int i = 1; i <= n; i++)
            add1(s, i, 0);
        if (dfs(s)) cout << "false" << endl;
        else cout << "true" << endl;
    }
    return 0;
}

