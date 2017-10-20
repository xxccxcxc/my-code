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
int n,m,a[3001][3001],f[3001][3001],t,minn;
int main()
{
    scanf ("%d%d",&m,&n);
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        scanf ("%d",&a[j][i]);
    for (int i=1;i<=m;i++)
      for (int j=1;j<=n;j++)
      {
          t=j-1;
          if (t==0)t=n;
          f[i][j]=min (f[i-1][j],f[i-1][t])+a[i][j];
      }
    minn=f[m][1];
    for (int i=1;i<=n;i++)minn=min(minn,f[m][i]);
    cout <<minn;
    return 0;
}

