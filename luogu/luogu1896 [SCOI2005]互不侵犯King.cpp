#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 10, MAXM = MAXN*MAXN, MAXS = 1<<MAXN;
int f[MAXN][MAXM][MAXS] = {0};
void init(int tot, bool p1[], bool p2[][MAXS], int *cnt)
{
    for (int i = 0; i < tot; ++i)
        if (!(i&(i>>1)))
        {
            p1[i] = true;
            int one = 0;
            for (int j = i; j; j >>= 1)
                one += j&1;
            cnt[i] = one;
        }
    for (int i = 0; i < tot; ++i)
        for (int j = 0; j < tot; ++j)
            if (!(i&j) && !(i&(j>>1)) && !(i&(j<<1)))
                p2[i][j] = true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int tot = 1<<n;
    bool p1[MAXS] = {0}, p2[MAXS][MAXS] = {0};
    int cnt[MAXS];
    init(tot, p1, p2, cnt);
    for (int i = 0; i < tot; ++i)
        if (p1[i]) f[1][cnt[i]][i] = 1;
    for (int i = 2; i <= n; ++i)
        for (int k = 0; k < tot; ++k)
            if (p1[k])
                for (int j = 0; j < tot; ++j)
                    if (p1[j] && p2[j][k])
                        for (int x = cnt[j]+cnt[k]; x <= m; ++x)
                            f[i][x][k] += f[i-1][x-cnt[k]][j];
    int ans = 0;
    for (int i = 0; i < tot; i++)
        ans += f[n][m][i];
    cout << ans << endl;
    return 0;
}
