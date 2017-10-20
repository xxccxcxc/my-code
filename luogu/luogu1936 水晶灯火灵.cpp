#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int k;
    scanf("%d", &k);
    int a = 1, b = 1;
    while (a + b <= k)
        if (a < b)a += b;
        else b += a;
    printf("m=%d\nn=%d\n", min(a, b), max(a, b));
    return 0;
}


