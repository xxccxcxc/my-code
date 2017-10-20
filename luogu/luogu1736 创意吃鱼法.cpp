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
int f[2501][2501][3],n,m,maxx=0;
int pd(int x,int y,int pp,int t)
{
    int t1=0,t2=0;
    if (pp==1)
    {
        for (int yy=y+1;yy<=y+t;yy++)
          if (!f[x][yy][1])++t1;else break;
    }
    else
    {
        for (int yy=y-1;yy>=y-t;yy--)
          if (!f[x][yy][1])++t1;else break;
    }
    for (int xx=x-1;xx>=x-t;xx--)
      if (!f[xx][y][1])++t2;else break;
    return min(t1,t2);
}
int main()
{
    cin >>n>>m;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        {scanf ("%d",&f[i][j][1]);f[i][j][2]=f[i][j][1];}
    for (int i=2;i<=n;i++)
    {
        if (f[i][1][1]&&f[i-1][2][1])f[i][1][1]=max(f[i][1][1],min(pd(i,1,1,f[i-1][2][1]),f[i-1][2][1])+1);
        if (f[i][m][2]&&f[i-1][m-1][2])f[i][m][2]=max(f[i][m][2],min(pd(i,m,2,f[i-1][m-1][2]),f[i-1][m-1][2])+1);
        for (int j=2;j<m;j++)
        {
            if (f[i][j][2]&&f[i-1][j-1][2])
              f[i][j][2]=max(f[i][j][2],min(pd(i,j,2,f[i-1][j-1][2]),f[i-1][j-1][2])+1);
            if (f[i][j][1]&&f[i-1][j+1][1])
              f[i][j][1]=max(f[i][j][1],min(pd(i,j,1,f[i-1][j+1][1]),f[i-1][j+1][1])+1);
        }
    }
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        maxx=max(maxx,max(f[i][j][1],f[i][j][2]));
    //for (int i=1;i<=n;i++){
    //  for (int j=1;j<=m;j++)
    //    cout <<f[i][j][1]<<' '<<f[i][j][2]<<' ';
    //  cout <<endl;}
    cout <<maxx;
    return 0;
}

