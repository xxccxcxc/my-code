#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int n, zys[10050] = {0};
    scanf ("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        int t = i;
        while (t > 1)
        {
            for (int j = 2; j <= t; j++)
                while (!(t % j))
                {
                    t /= j;
                    ++zys[j];
                }
        }
    }
    for (int i = 2; i <= n; i++)
        if (zys[i])
            printf("%d %d\n", i, zys[i]);
    return 0;
}


