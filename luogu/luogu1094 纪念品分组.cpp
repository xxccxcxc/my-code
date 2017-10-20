#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int n,m,a[30001]={0},x=1,d,ans=0;
    cin >>m>>n;
    d=n;
    for (int i=1;i<=n;i++)cin >>a[i];
    sort (a+1,a+n+1);
    while (x<=d)
    {
        if (a[x]+a[d]<=m)++x;
        --d,++ans;
    }
    cout <<ans;
    return 0;
}

