#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 150;
const double INF = 123456;
int x[N], y[N];
double getDis(int u, int v)
{
    return sqrt((x[u]-x[v])*(x[u]-x[v]) + (y[u]-y[v])*(y[u]-y[v]));
}
int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    cin >> m;
    double dis[N][N];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = INF;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        dis[u][v] = dis[v][u] = getDis(u, v);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j && j != k && i != k)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    int s, t;
    cin >> s >> t;
    printf("%.2lf\n", dis[s][t]);
    return 0;
}

