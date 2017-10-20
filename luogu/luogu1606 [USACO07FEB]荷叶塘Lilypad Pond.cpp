#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int R = 35, C = 35, N = 35*35, M = N*N, INF = 0x3f3f3f3f;
const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
struct Edge
{
    int to, next;
}edge[M*2];
int e, head[N];
int r, c, st, ed;
int a[R][C];
bool v1[R][C], vis[N];
int dis[N];
long long f[N];
void add1(int u, int v)
{
    edge[e].to = v;
    edge[e].next = head[u];
    head[u] = e++;
}
int num(int x, int y)
{
    return (x-1) * c + y;
}
void dfs(int s, int x, int y)
{
    v1[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > r || yy < 1 || yy > c || v1[xx][yy])
            continue;
        if (a[xx][yy] == 1) dfs(s, xx, yy);
        if (!a[xx][yy]) v1[xx][yy] = true, add1(s, num(xx, yy));
    }
}
void SPFA()
{
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.push(st);
    dis[st] = 0; vis[st] = true; f[st] = 1;
    while (!q.empty())
    {
        int u = q.front(); q.pop(); vis[u] = false;
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dis[u] + 1 < dis[v])
            {
                dis[v] = dis[u] + 1;
                f[v] = f[u];
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
            else if (dis[u] + 1 == dis[v])
                f[v] += f[u];
        }
    }
}
int main()
{
    memset(head, -1, sizeof(head));
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 3) st = num(i, j), a[i][j] = 0;
            if (a[i][j] == 4) ed = num(i, j), a[i][j] = 0;
        }
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (!a[i][j])
            {
                memset(v1, 0, sizeof(v1));
                dfs(num(i, j), i, j);
            }
    SPFA();
    if (dis[ed] < INF) cout << dis[ed]-1 << endl << f[ed] << endl;
    else cout << -1 << endl;
    return 0;
}

