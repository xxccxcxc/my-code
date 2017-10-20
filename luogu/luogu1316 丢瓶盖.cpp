#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,m,a[100001],l,r,mid,s,t;
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;i++)scanf ("%d",&a[i]);
    sort (a+1,a+n+1);
    l=1;r=(a[n]-a[1])/(m-1);
    while (l<r)
    {
        mid=(l+r)/2;
        t=1;s=a[1];
        for (int i=2;i<=n;i++)
          if (a[i]-s>mid){++t;s=a[i];}
        if (t>=m)l=mid+1;else r=mid;
    }
    printf ("%d",l);
    return 0;
}

