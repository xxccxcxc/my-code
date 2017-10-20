#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#define BIG 100000000
using namespace std;
int n,x[100005],y[100005];
double f[155][155],m[155],ans=0x7fffffff;
double dis(int t1,int t2)
{
    return sqrt((x[t1]-x[t2])*(x[t1]-x[t2])+(y[t1]-y[t2])*(y[t1]-y[t2]));
}
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)cin >>x[i]>>y[i];
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
            char r;
            cin >>r;
            if (r=='1')f[i][j]=dis(i,j);
            else f[i][j]=BIG;
      }
    for (int k=1;k<=n;k++)
      for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
          if (i!=j&&i!=k&&j!=k)
            f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
        if (f[i][j]<BIG)
          m[i]=max(m[i],f[i][j]);
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
        if (i!=j&&f[i][j]>=BIG)
          ans=min(ans,m[i]+m[j]+dis(i,j));
    for (int i=1;i<=n;i++)ans=max(ans,m[i]);
    printf ("%.6lf",ans);
     return 0;
}

