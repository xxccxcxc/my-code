#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
using namespace std;
const int INF = 987654321;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int n, m;
int vis[1550][1550][2];
bool a[1550][1550];
bool dfs(int cx, int cy, int px, int py)
{
    if (vis[cx][cy][0] == INF)
    {
        vis[cx][cy][0] = px;
        vis[cx][cy][1] = py;
    }
    else
        return vis[cx][cy][0] != px || vis[cx][cy][1] != py;
    for (int i = 0; i < 4; i++)
    {
        int xx = cx + dx[i], yy = cy + dy[i], tpx = px, tpy = py;
        if (xx < 0)
        {
            xx = n - 1;
            --tpx;
        }
        if (xx >= n)
        {
            xx = 0;
            ++tpx;
        }
        if (yy < 0)
        {
            yy = m - 1;
            --tpy;
        }
        if (yy >= m)
        {
            yy = 0;
            ++tpy;
        }
        if (!a[xx][yy] && dfs(xx, yy, tpx, tpy))
            return true;
    }
    return false;
}
int main()
{
    while (cin >> n >> m)
    {
        memset(vis, 0, sizeof(vis));
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                vis[i][j][0] = vis[i][j][1] = INF;
        char r;
        int sx, sy;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> r;
                if (r == '#')
                    a[i][j] = true;
                else if (r == 'S')
                {
                    sx = i;
                    sy = j;
                }
            }
        cout << (dfs(sx, sy, 0, 0) ? "Yes" : "No") << endl;
    }
    return 0;
}


