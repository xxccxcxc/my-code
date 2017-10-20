#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int N = 5050;
const double INF = 1023456789;
double x[N], y[N];
double dis(int u, int v)
{
    return sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    bool vis[N] = {0};
    double f[N], ans = 0;
    for (int i = 0; i <= n; i++)
        f[i] = INF;
    f[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && f[j] < f[k])
                k = j;
        vis[k] = true; ans += f[k];
        for (int j = 1; j <= n; j++)
            if (!vis[j])
                f[j] = min(f[j], dis(k, j));
    }
    printf("%.2lf", ans);
    return 0;
}

