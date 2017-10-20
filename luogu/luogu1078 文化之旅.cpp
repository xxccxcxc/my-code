#include <cstdio>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
int main()  
{  
    int n,k,m,s,t,sr,a[101][101]={0},r1,r2,c[101]={0},p[101][101]={0};
    cin >>n>>k>>m>>s>>t;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
        a[i][j]=200000000;
    for (int i=1;i<=n;i++)cin >>c[i];
    for (int i=1;i<=k;i++)
      for (int j=1;j<=k;j++)
        cin >>p[i][j];
    for (int i=1;i<=m;i++)
    {
        cin >>r1>>r2>>sr;
        if (!p[c[r2]][c[r1]])
          a[r1][r2]=sr;
        if (!p[c[r1]][c[r2]])
          a[r2][r1]=sr;
    }
    for (int k=1;k<=n;k++)
      for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
          if (i!=j&&j!=k&&k!=i)
            if (!p[c[k]][c[i]]&&!p[c[j]][c[k]]&&!p[c[j]][c[i]])
              a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    if (a[s][t]==200000000)cout <<-1;
    else cout <<a[s][t];
    return 0;  
}  
