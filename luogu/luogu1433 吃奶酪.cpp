#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int n;
double a[17][17],b[17][2],p[17],lc,m=2147483647;
double jl(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void dfs(int t,int l)
{
    if (lc>m)return;
    for (int i=1;i<=n+1;i++)
    {
        if (!p[i])
        {
            p[i]=1;
            lc+=a[l][i];
            if (t==n){if (lc<m)m=lc;}
            else dfs (t+1,i);
            p[i]=0;
            lc-=a[l][i];
        }
    }
}
int main()
{
    cin >>n;
    for (int i=2;i<=n+1;i++)cin >>b[i][1]>>b[i][2];
    for (int i=1;i<=n+1;i++)
      for (int j=1;j<=n+1;j++)
        a[i][j]=jl(b[i][1],b[i][2],b[j][1],b[j][2]);
    p[1]=1;
    dfs (1,1);
    printf ("%0.2lf",m);
    return 0;
}

