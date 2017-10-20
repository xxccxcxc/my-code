#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int n, ans = 0;
    bool f[20000] = {0};
    scanf ("%d", &n);
    for (int i = 0; i * i <= n; i++)
        f[i * i] = true;
    for (int i = 0; i * i <= n; i++)
        for (int j = 0; i * i + j * j <= n; j++)
            for (int k = 0; i * i + j * j + k * k <= n; k++)
                ans += f[n - i * i - j * j - k * k];
    printf("%d\n", ans);
    return 0;
}


