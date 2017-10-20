#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f, MAXN = 31;
int main()
{
    int n, m, a[MAXN], b[MAXN];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    int ans = INF;
    for (int i = 0; i < (1<<n) && ans; i++)
    {
        int ta = 0, tb = 0;
        for (int j = 0; j < n; j++)
            if (!(i & (1<<j)))
                ta += a[j], tb += b[j];
        if (ta + tb >= m) ans = min(ans, abs(ta-tb));
    }
    if (ans < INF) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}
