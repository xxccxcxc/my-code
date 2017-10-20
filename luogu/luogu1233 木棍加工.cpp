#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int n,a[5001],b[5001],m,c[5001],t;
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)cin >>a[i]>>b[i];
    for (int i=1;i<n;i++)
      for (int j=i+1;j<=n;j++)
        if (a[i]>a[j]||a[i]==a[j]&&b[i]>b[j])
          {swap(a[i],a[j]);swap(b[i],b[j]);}
    //for (int i=1;i<n;i++)cout <<a[i]<<' '<<b[i]<<endl;
    m=1;c[1]=b[1];
    for (int i=1;i<=n;i++)
    {
        t=0;
        for (int j=1;j<=m;j++)
          if (b[i]>=c[j])
            if (t==0||c[j]>c[t])
              t=j;
        if (!t)c[++m]=b[i];
        else c[t]=b[i];
    }
    cout <<m;
    return 0;
}

