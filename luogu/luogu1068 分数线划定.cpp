#include <iostream>
using namespace std;
int main()
{
    int n,a[5001],b[5001],t,tt=0,m,s=0;
    cin >>n>>m;
    for (int i=1;i<=n;i++)cin >>b[i]>>a[i];
    for (int i=1;i<n;i++)
      for (int j=1;j<=n-i;j++)
        if (b[j]>b[j+1])
        {
            t=a[j];a[j]=a[j+1];a[j+1]=t;
            t=b[j];b[j]=b[j+1];b[j+1]=t;
        }
    for (int i=1;i<n;i++)
      for (int j=1;j<=n-i;j++)
        if (a[j]<a[j+1])
        {
            t=a[j];a[j]=a[j+1];a[j+1]=t;
            t=b[j];b[j]=b[j+1];b[j+1]=t;
        }
    t=a[int(m*1.5)];
    cout <<t<<' ';
    while (a[++tt]>=t)++s;
    cout <<s<<endl;
    tt=0;
    while (a[++tt]>=t)cout <<b[tt]<<' '<<a[tt]<<endl;
    return 0;
}

