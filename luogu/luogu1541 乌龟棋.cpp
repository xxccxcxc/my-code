#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#define mo 10007
using namespace std;
int n,m,a[400]={0},f[45][45][45][45]={0},b[5]={0},sr;
int main()
{
    cin >>n>>m;
    for (int i=1;i<=n;i++)cin >>a[i];
    for (int i=1;i<=m;i++)
    {
        cin >>sr;
        ++b[sr];
    }
    f[0][0][0][0]=a[1];
    for (int i=0;i<=b[1];i++)
      for (int j=0;j<=b[2];j++)
        for (int k=0;k<=b[3];k++)
          for (int l=0;l<=b[4];l++)
          {
              if (i)f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]+a[i*1+j*2+k*3+l*4+1]);
              if (j)f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l]+a[i*1+j*2+k*3+l*4+1]);
              if (k)f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k-1][l]+a[i*1+j*2+k*3+l*4+1]);
              if (l)f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k][l-1]+a[i*1+j*2+k*3+l*4+1]);
          }
    cout <<f[b[1]][b[2]][b[3]][b[4]];
    return 0;
}
