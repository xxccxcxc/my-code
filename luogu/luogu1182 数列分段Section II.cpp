#include <iostream>
using namespace std;
int main()
{
    int a[100001],n,m,l,r,s,mid,t;
    cin >>n>>m>>a[1];
    if (n==0||m==0){cout <<0;return 0;}
    l=r=a[1];
    for (int i=2;i<=n;i++){cin >>a[i];if (a[i]>l)l=a[i];r+=a[i];}
    while (l<r)
    {
        mid=(l+r)/2;
        s=0;t=1;
        for (int i=n;i>=1;i--)
        {
            if (s+a[i]<=mid)s+=a[i];
            else {++t;s=a[i];}
        }
        if (t>m)l=mid+1;else r=mid;
    }
    cout <<l;
    return 0;
}

