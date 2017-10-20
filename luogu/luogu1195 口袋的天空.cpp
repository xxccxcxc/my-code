#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1050, M = 10050;
struct Edge
{
    int u, v, w;
}edge[M];
int n, m, k;
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
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    sort(edge+1, edge+m+1, cmp);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int cnt = 0, ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int fu = find(edge[i].u), fv = find(edge[i].v);
        if (fu != fv)
        {
            fa[fu] = fv;
            ans += edge[i].w;
            if (++cnt == n-k)
                break;
        }
    }
    cout << (cnt == n-k ? ans : -1) << endl;
    return 0;
}

