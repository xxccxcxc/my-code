#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2050;
const double INF = 0x3f3f3f3f;
double a[N][N];
int main()
{
    int n, m, s, t;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = -1;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = a[v][u] = 1-(w/100.0);
    }
    cin >> s >> t;
    double f[N];
    bool vis[N] = {0};
    for (int i = 1; i <= n; i++)
        f[i] = INF;
    f[t] = 100; f[0] = INF;
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && f[j] < f[k])
                k = j;
        vis[k] = true;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && a[k][j] != -1)
                f[j] = min(f[j], f[k] / a[k][j]);
    }
    printf("%.8lf\n", f[s]);
    return 0;
}

