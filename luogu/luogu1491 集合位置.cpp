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
using namespace std;
int n,m;
int x[205],y[205];
double a[205][205];
int pre[205];
double dis(int t1,int t2)
{
    return sqrt((x[t1]-x[t2])*(x[t1]-x[t2])+(y[t1]-y[t2])*(y[t1]-y[t2]));
}
double dij(int pd)
{
    double f[205]={0};
    bool p[205]={0};
    f[1]=0;p[1]=1;
    for (int i=2;i<=n;i++){f[i]=a[1][i];if (pd)pre[i]=1;}
    for (int i=1;i<n;i++)
    {
        int t=0,minn=0x7fffffff;
        for (int j=1;j<=n;j++)
          if (!p[j]&&f[j]<minn)
          {minn=f[j];t=j;}
        p[t]=1;
        for (int j=1;j<=n;j++)
          if (f[t]+a[t][j]<f[j])
          {f[j]=f[t]+a[t][j];if (pd)pre[j]=t;}
    }
    return f[n];
} 
int main()
{
    cin >>n>>m;
    for (int i=1;i<=n;i++)cin >>x[i]>>y[i];
    memset (a,0x7f,sizeof(a));
    for (int i=1;i<=m;i++)
    {
        int r1,r2;
        cin >>r1>>r2;
        a[r1][r2]=a[r2][r1]=dis(r1,r2);
    }
    double s=dij(1),ans=0x7fffffff;
    for (int i=n;i!=1;i=pre[i])
    {
        double tt=a[pre[i]][i];
        a[pre[i]][i]=a[i][pre[i]]=2000000000;
        ans=min(ans,dij(0));
        a[pre[i]][i]=a[i][pre[i]]=tt;
    }
    printf ("%.2lf",ans);
    return 0;
}

