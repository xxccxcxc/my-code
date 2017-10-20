#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 10050, MAXM = 1050, INF = 0x3f3f3f3f;
int f[2][MAXM];
int main()
{
    int n, m, k;
    int up[MAXN], down[MAXN], low[MAXN] = {0}, high[MAXN];
    bool p[MAXN];
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%d%d", up+i, down+i);
    for (int i = 0; i <= n; i++)
        high[i] = m+1;
    for (int i = 0, x; i < k; i++)
        scanf("%d", &x), scanf("%d%d", low+x, high+x), p[x] = true;
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= m; i++)
        f[0][i] = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int cur = i&1, pre = cur^1;
        memset(f[cur], 0x3f, sizeof(f[cur]));
        for (int j = up[i-1]; j <= m; j++)
            if (j != m)
                f[cur][j] = min(f[cur][j], min(f[pre][j-up[i-1]]+1, f[cur][j-up[i-1]]+1));
            else
                for (int k = m-up[i-1]; k <= m; k++)
                    f[cur][j] = min(f[cur][j], min(f[pre][k]+1, f[cur][k]+1));
        for (int j = low[i]+1; j < high[i] && j+down[i-1] <= m; j++)
            f[cur][j] = min(f[cur][j], f[pre][j+down[i-1]]); 
        for (int j = 1; j <= low[i]; j++)
            f[cur][j] = INF;
        for (int j = high[i]; j <= m; j++)
            f[cur][j] = INF;
        int minn = INF;
        //for (int j = low[i]+1; j < high[i]; j++)
        //    cout << i << ' ' << j << ' ' << f[cur][j] << endl;
        for (int j = low[i]+1; j < high[i]; j++)
            minn = min(minn, f[cur][j]);
        if (minn < INF)
        {
            cnt += p[i];
            if (i == n)
                printf("1\n%d\n", minn);
        }
        else
        {
            printf("0\n%d\n", cnt);
            break;
        }
    }
    return 0;
}
