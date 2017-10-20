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
int n,m,a[11][16]={0},f[11][16]={0};
void dg(int i,int j,int t)
{
    if (i==0)return;
    for (int k=0;k<=j;k++)
      if (f[i-1][k]+a[i][j-k]==t)
      {
          dg(i-1,k,f[i-1][k]);
          cout <<i<<' '<<j-k<<endl;
          return;
      }
}
int main()
{
    cin >>n>>m;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        cin >>a[i][j];
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        for (int k=0;k<=j;k++)
          f[i][j]=max(f[i][j],f[i-1][k]+a[i][j-k]);
    cout <<f[n][m]<<endl;
    dg(n,m,f[n][m]);
    return 0;
}

