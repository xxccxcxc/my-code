#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    int n,m,a[201][201],f[202][202]={0},t;
    cin >>n>>m;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        cin >>a[i][j];
    for (int i=1;i<=n;i++)
    {
        f[i][1]=max(f[i-1][1],f[i-1][2])+a[i][1];
        f[i][m]=max(f[i-1][m-1],f[i-1][m])+a[i][m];
        for (int j=2;j<m;j++)f[i][j]=max(f[i-1][j-1],max(f[i-1][j],f[i-1][j+1]))+a[i][j];
    }
    t=m/2+1;
    cout <<max(f[n][t-1],max(f[n][t],f[n][t+1]));
    return 0;
}
