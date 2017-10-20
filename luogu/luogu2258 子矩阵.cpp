#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int n,m,r,c,a[17][17],b[17],f[17][17],tt,ttt,ans=0x7fffffff;
void dp()
{
    for (int i=1;i<=16;i++)
      for (int j=1;j<=16;j++)
        f[i][j]=0x7fffffff;
    for (int i=1;i<=m;i++)
    {
        tt=0;
        for (int j=1;j<r;j++)
          tt+=abs(a[b[j]][i]-a[b[j+1]][i]);
        f[i][1]=tt;
        for (int j=2;j<=i&&j<=c;j++)
        {
            for (int k=j-1;k<i;k++)
            {
                ttt=0;
                for (int l=1;l<=r;l++)
                  ttt+=abs(a[b[l]][i]-a[b[l]][k]);
                f[i][j]=min(f[i][j],f[k][j-1]+tt+ttt);
            }
        }
    }
    for (int i=c;i<=m;i++)ans=min(ans,f[i][c]);
    return;
}
void dfs(int d,int t)
{
    if (t==r)dp();
    if (r-t>n-d)return;
    for (int i=d+1;i<=n;i++)
      {b[t+1]=i;dfs(i,t+1);}
    return;
}
int main()
{
    cin >>n>>m>>r>>c;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        cin >>a[i][j];
    dfs(0,0);
    cout <<ans;
    return 0;
}

