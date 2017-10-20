#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1550;
int n, a[N][N];
int ans[N], top;
void dfs(int u)
{
    for (int i = 1; i <= n; i++)
        if (a[u][i])
        {
            --a[u][i]; --a[i][u];
            dfs(i);
        }
    ans[top++] = u;
}
int main()
{
    int m, du[N] = {0};
    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        ++a[u][v]; ++a[v][u];
        ++du[u]; ++du[v];
        n = max(n, max(u, v));
    }
    int st = 1; 
    for (int i = 1; i <= n; i++)
        if (du[i] % 2)
        {
            st = i;
            break;
        }
    dfs(st);
    for (int i = top-1; i >= 0; i--)
        cout << ans[i] << endl;
    return 0;
}

