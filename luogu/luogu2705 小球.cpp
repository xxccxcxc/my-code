#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define INF 987654321
using namespace std;
int main()
{
    int r, b, c, d, e;
    int ans = -INF;
    scanf("%d%d%d%d%d", &r, &b, &c, &d, &e);
    for (int i = 0; i <= min(r, b); i++)
        ans = max(ans, 2 * i * e + (r - i) * c + (b - i) * d);
    printf("%d\n", ans);
    return 0;
}

