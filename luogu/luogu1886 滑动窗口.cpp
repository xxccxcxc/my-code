#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 1000050;
struct Node
{
    int val, pos;
};
Node qmin[MAXN];
int h1, t1=-1, ans1[MAXN];
Node qmax[MAXN];
int h2, t2=-1, ans2[MAXN];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        int sr;
        scanf("%d", &sr);
        Node u;
        u.val = sr, u.pos = i;
        while (h1 <= t1 && i - qmin[h1].pos >= k) ++h1;
        while (h2 <= t2 && i - qmax[h2].pos >= k) ++h2;
        while (h1 <= t1 && qmin[t1].val >= sr) --t1;
        while (h2 <= t2 && qmax[t2].val <= sr) --t2;
        qmin[++t1] = qmax[++t2] = u;
        if (i >= k) ans1[i] = qmin[h1].val, ans2[i] = qmax[h2].val;
    }
    for (int i = k; i <= n; i++) printf("%d ", ans1[i]);
    cout << endl;
    for (int i = k; i <= n; i++) printf("%d ", ans2[i]);
    return 0;
}

