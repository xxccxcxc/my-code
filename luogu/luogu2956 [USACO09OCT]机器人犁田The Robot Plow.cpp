#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int n, m, q, ans = 0;
    bool p[300][300] = {0};
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= q; i++)
    {
        int lx, ly, rx, ry;
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        for (int x = lx; x <= rx; x++)
            for (int y = ly; y <= ry; y++)
                if (!p[x][y])
                {
                    p[x][y] = true;
                    ++ans;
                }
    }
    printf ("%d\n", ans);
    return 0;
}


