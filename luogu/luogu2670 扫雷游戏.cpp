#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    int n,m,a[101][101]={0},x[9]={0,-1,-1,0,1,1,1,0,-1},y[9]={0,0,1,1,1,0,-1,-1,-1};
    char sr;
    cin >>n>>m;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
          cin >>sr;
          if (sr=='*')a[i][j]=-1;
      }
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        if (a[i][j]==-1)
        {
            for (int k=1;k<=8;k++)
            {
                int xx=i+x[k],yy=j+y[k];
                if (xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]!=-1)
                {
                    ++a[xx][yy];
                }
            }
        }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
          if (a[i][j]==-1)cout <<'*';
          else cout <<a[i][j];
        cout <<endl;
    }
    return 0;
}

