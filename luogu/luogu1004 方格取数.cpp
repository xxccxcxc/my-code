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
int n,sx,sy,st,a[11][11]={0},f[11][11][11][11]={0};
int main()
{
    cin >>n;
    while (1)
    {
        cin >>sx>>sy>>st;
        if (sx==0&&sy==0&&st==0)break;
        a[sx][sy]=st;
    }
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
        for (int k=1;k<=n;k++)
          for (int l=1;l<=n;l++)
          {
              f[i][j][k][l]=max(f[i-1][j][k-1][l],max(f[i-1][j][k][l-1],max(f[i][j-1][k-1][l],f[i][j-1][k][l-1])))+a[i][j]+a[k][l];
              if (i==k&&j==l)f[i][j][k][l]-=a[i][j];
          }
    cout <<f[n][n][n][n];
    return 0;
}

