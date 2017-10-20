#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int n, x[55], y[55], r[55];
int xa, ya, xb, yb, ans = 0;
bool pd(int tx, int ty, int u)
{
    int dis = (tx - x[u]) * (tx - x[u]) + (ty - y[u]) * (ty - y[u]);
    return dis < r[u] * r[u];
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &x[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &y[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &r[i]);
    scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
    for (int i = 1; i <= n; i++)
        ans += pd(xa, ya, i) ^ pd(xb, yb, i);
    printf("%d\n", ans);
    return 0;
}


