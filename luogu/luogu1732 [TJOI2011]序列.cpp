#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, m, a[200][200], f[200][200], ans = 0;
int dfs(int x, int y)
{
    if (f[x][y]) return f[x][y];
    for (int i = 0; i < 4; i++)
    {
        int xx = x+dx[i], yy = y+dy[i];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && a[xx][yy] > a[x][y])
            f[x][y] = max(f[x][y], dfs(xx, yy)+1);
    }
    return f[x][y];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, dfs(i, j));
    cout << ans << endl;
    return 0;
}

