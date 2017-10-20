#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 250, INF = 0x3f3f3f3f;
int main()
{
    int n, m;
    cin >> n >> m;
    int t[N], dis[N][N];
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 0; i < n; i++)
        cin >> t[i];
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = w;
    }
    bool vis[N] = {0};
    int q;
    cin >> q;
    while (q--)
    {
        int u, v, tt;
        cin >> u >> v >> tt;
        if (t[u] > tt || t[v] > tt)
        {
            cout << -1 << endl;
            continue;
        }
        for (int k = 0; k < n; k++)
            if (!vis[k] && t[k] <= tt)
            {
                vis[k] = true;
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        if (i != j && j != k && i != k)
                            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        cout << (dis[u][v] == INF ? -1 : dis[u][v]) << endl; 
    }
    return 0;
}

