#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 250, M = 6050;
struct Edge
{
    int u, v, w, time;
}edge[M];
int n, m;
int fa[N];
bool cmp(Edge t1, Edge t2)
{
    return t1.w < t2.w;
}
int find(int x)
{
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}
int kruskal(int now)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int cnt = 0, ret = 0;
    for (int i = 1; i <= m; i++)
    {
        if (edge[i].time > now) continue;
        int fu = find(edge[i].u), fv = find(edge[i].v);
        if (fu != fv)
        {
            fa[fu] = fv;
            ret += edge[i].w;
            if (++cnt == n-1)
                break;
        }
    }
    return cnt == n-1 ? ret : -1;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        edge[i].time = i;
    }
    sort(edge+1, edge+m+1, cmp);
    for (int i = 1; i <= m; i++)
        cout << kruskal(i) << endl;
    return 0;
}

