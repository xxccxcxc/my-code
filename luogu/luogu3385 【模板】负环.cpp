#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 200050, M = 200050;
struct Edge
{
    int to, w, next;
}edge[M*2];
int e, head[N];
int T, n, m;
bool vis[N], flag;
int dis[N];
void clear()
{
    e = 0;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    flag = false;
}
void add1(int u, int v, int w)
{
    edge[e].to = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
}
void dfs(int u)
{
    if (flag) return;
    vis[u] = true;
    for (int i = head[u]; ~i && !flag; i = edge[i].next)
    {
        int v = edge[i].to;
        if (dis[u] + edge[i].w < dis[v])
        {
            dis[v] = dis[u] + edge[i].w;
            if (vis[v]) flag = true;
            else dfs(v);
        }
    }
    vis[u] = false;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        clear();
        scanf("%d%d", &n, &m);
        int u, v, w;
        while (m--)
        {
            scanf("%d%d%d", &u, &v, &w);
            add1(u, v, w);
            if (w >= 0) add1(v, u, w);
        }
        for (int i = 1; i <= n && !flag; i++)
            if (!vis[i]) dfs(i);
        if (flag) cout << "YE5" << endl;
        else cout << "N0" << endl;
    }
    return 0;
}

