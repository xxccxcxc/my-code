#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 30050, M = 5050;
struct Req
{
    int l, r, cnt;
}req[N];
bool cmp(Req t1, Req t2)
{
    return t1.r < t2.r;
}
int main()
{
    int n, m;
    cin >> n >> m; 
    for (int i = 1; i <= m; i++)
        cin >> req[i].l >> req[i].r >> req[i].cnt;
    sort(req+1, req+m+1, cmp);
    bool p[N] = {0};
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int t = req[i].cnt;
        for (int j = req[i].l; j <= req[i].r && t; j++)
            if (p[j]) --t;
        for (int j = req[i].r; j >= req[i].l && t; j--)
            if (!p[j]) p[j] = true, --t, ++ans;
    }
    cout << ans << endl;
    return 0;
}

