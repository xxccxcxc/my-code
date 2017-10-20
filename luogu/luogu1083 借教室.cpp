#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1000050;
int n, m, a[MAXN], d[MAXN], s[MAXN], t[MAXN], b[MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> d[i] >> s[i] >> t[i];
    int l = 1, r = m+1;
    while (l < r)
    {
        int mid = (l+r)>>1;
        for (int i = 1; i <= n+1; i++)
            b[i] = 0;
        for (int i = 1; i <= mid; i++)
            b[s[i]] -= d[i], b[t[i]+1] += d[i];
        int tmp = 0;
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            tmp += b[i];
            if (a[i]+tmp < 0)
            {
                ok = false;
                break;
            }
        }
        if (ok) l = mid+1;
        else r = mid;
    }
    if (l > m) printf("0\n");
    else printf("-1\n%d\n", l);
    return 0;
}

