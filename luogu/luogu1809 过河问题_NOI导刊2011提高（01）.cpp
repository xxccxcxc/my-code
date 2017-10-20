#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
int n,a[1000001],f[1000001];
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)cin >>a[i];
    sort (a+1,a+n+1);
    f[1]=a[1];if (n>=2)f[2]=a[2];
    for (int i=3;i<=n;i++)f[i]=min(a[1]+2*a[2]+a[i]+f[i-2],f[i-1]+a[1]+a[i]);
    cout <<f[n];
    return 0;
}

