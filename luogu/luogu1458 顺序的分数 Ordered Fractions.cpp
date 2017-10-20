#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}
struct Num
{
    double val;
    int a, b;
}num[1000000];
int top = 0;
bool cmp(Num t1, Num t2)
{
    return t1.val > t2.val;
}
int main()
{
    int n;
    cin >> n;
    cout << "0/1\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (gcd(i, j) == 1)
            {
                num[++top].a = j;
                num[top].b = i;
                num[top].val = i*1.0/j;
            }
    sort(num+1, num+top+1, cmp);
    for (int i = 1; i <= top; i++)
        printf("%d/%d\n", num[i].a, num[i].b);
    return 0;
}

