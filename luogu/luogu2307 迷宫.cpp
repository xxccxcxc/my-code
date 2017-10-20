#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100010;
int fa[N];
int find(int x)
{
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}
int main()
{
    int u, v;
    while (cin >> u >> v)
    {
        if (u == -1 && v == -1) break;
        for (int i = 1; i <= N; i++)
            fa[i] = i;
        int mx = 0;
        bool ok = true, vis[N] = {0};
        while (u && v)
        {
            if (ok)
            {
                mx = max(mx, max(u, v));
                vis[u] = vis[v] = true;
                int fu = find(u), fv = find(v);
                if (fu == fv) ok = false;
                else fa[fu] = fv;
            }
            cin >> u >> v;
        }
        int cnt = 0;
        for (int i = 1; i <= mx && ok; i++)
        {
            if (vis[i] && fa[i] == i) ++cnt;
            if (cnt > 1) ok = false;
        }
        if (ok) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}

