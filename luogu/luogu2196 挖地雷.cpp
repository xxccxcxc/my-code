#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    int n,a[21],b[21][21]={0},c[21]={0},f[21]={0},maxx,t;
    cin >>n;
    for (int i=1;i<=n;i++)cin >>a[i];
    for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
        cin >>b[i][j];
    f[n]=a[n];
    maxx=n;
    f[0]=-1;
    for (int i=n-1;i>=1;i--)
    {
        for (int j=i+1;j<=n;j++)
          if (b[i][j]&&f[j]>f[c[i]])c[i]=j;
        f[i]=a[i]+f[c[i]];
        if (c[i]==0)f[i]=a[i];
        if (f[i]>=f[maxx])maxx=i;
    }
    t=f[maxx];
    while (maxx)
    {
        cout <<maxx<<' ';
        maxx=c[maxx];
    }
    cout <<endl<<t;
    return 0;
}

