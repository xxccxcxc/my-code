#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int n, a, b, c;
    scanf ("%d%d%d%d", &n, &a, &b, &c);
    if (!(n % 2) || (abs(a-b) == 1) + (abs(b-c) == 1) + (abs(a-c) == 1) == 2)
        printf ("JMcat Win");
    else printf ("PZ Win");
    return 0;
}


