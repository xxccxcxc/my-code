#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int n, r, a[50] = {0};
    bool zj[50] = {false};
    scanf("%d", &n);
    for (int i = 1; i <= 7; i++)
    {
        scanf("%d", &r);
        zj[r] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= 7; j++)
        {
            scanf("%d", &r);
            sum += zj[r];
        }
        ++a[7-sum];
    }
    for (int i = 0; i < 7; i++)
        printf ("%d ", a[i]);
    return 0;
}

