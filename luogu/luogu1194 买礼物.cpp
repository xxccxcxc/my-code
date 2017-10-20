#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 550, INF = 0x3f3f3f3f;
int main()
{
    int c, n, dis[N][N];
    cin >> c >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> dis[i][j];
            if (i == j) dis[i][j] = INF;
            if (!dis[i][j]) dis[i][j] = c;
        }
    bool vis[N] = {0};
    int f[N];
    memset(f, 0x3f, sizeof(f));
    f[0] = INF; f[1] = 0;
    int ans = c;
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && f[j] < f[k])
                k = j;
        vis[k] = true; ans += f[k];
        for (int j = 1; j <= n; j++)
            if (!vis[j])
                f[j] = min(f[j], dis[k][j]);
    }
    cout << ans << endl;
    return 0;
}

