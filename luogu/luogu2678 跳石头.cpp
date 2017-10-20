#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int L,n,m,a[50005]={0};
    cin >>L>>n>>m;
    for (int i=1;i<=n;i++)cin >>a[i];
    a[n+1]=L;
    int l=0,r=L,mid;
    while (l<r)
    {
        mid=(l+r)/2+1;
        //cout <<l<<' '<<r<<' '<<mid<<endl;
        int t=0,tt=0;
        for (int i=1;i<=n+1;i++)
          if (a[i]-a[t]>=mid)t=i;
          else ++tt;
        if (tt<=m)l=mid;
        else r=mid-1;
    }
    cout <<l;
    return 0;
}
