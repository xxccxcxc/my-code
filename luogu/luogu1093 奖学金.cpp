#include <iostream>
using namespace std;
int main()
{
    int n,a[10001],b[10001],c[10001],t,t1,t2,t3;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>t1>>t2>>t3;
        b[i]=t1;
        a[i]=t1+t2+t3;
        c[i]=i;
    }
    for (int i=1;i<n;i++)
      for (int j=1;j<=n-i;j++)
        if (b[j]<b[j+1])
        {
            t=a[j];a[j]=a[j+1];a[j+1]=t;
            t=b[j];b[j]=b[j+1];b[j+1]=t;
            t=c[j];c[j]=c[j+1];c[j+1]=t;
        }
    for (int i=1;i<n;i++)
      for (int j=1;j<=n-i;j++)
        if (a[j]<a[j+1])
        {
            t=a[j];a[j]=a[j+1];a[j+1]=t;
            t=b[j];b[j]=b[j+1];b[j+1]=t;
            t=c[j];c[j]=c[j+1];c[j+1]=t;
        }
    for (int i=1;i<=5;i++)cout <<c[i]<<' '<<a[i]<<endl;
    return 0;
}

