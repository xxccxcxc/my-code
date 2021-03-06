#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1050, M = 5050, INF = 0x3f3f3f3f;
struct Edge
{
    int to, w, next;
}edge[M*4];
int e, head[N];
int dis[N];
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
        int u, v, w;
        cin >> u >> v >> w;
        add1(v, u, w);
    }
    for (int i = 1; i <= n; i++)
        add1(0, i, 0);
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0; 
    if (dfs(0)) cout << "NO SOLUTION" << endl;
    else
    {
        int minn = INF;
        for (int i = 1; i <= n; i++)
            minn = min(minn, dis[i]);
        for (int i = 1; i <= n; i++)
            cout << dis[i]-minn << endl;
    }
    return 0;
}

