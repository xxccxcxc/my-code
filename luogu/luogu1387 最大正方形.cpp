#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int n,m;
bool a[101][101];
bool pd(int x,int xx,int y,int yy)
{
    for (int i=x;i<=xx;i++)
      for (int j=y;j<=yy;j++)
        if (a[i][j]==0)
          return 0;
    return 1;
}
int main()
{
    cin >>n>>m;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        cin >>a[i][j];
    for (int k=min(n,m);k>=1;k--)
      for (int i=1;i<=n-k+1;i++)
        for (int j=1;j<=m-k+1;j++)
          if (pd(i,i+k-1,j,j+k-1))
            {cout <<k;return 0;}
    return 0;
}
