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
int a[40][40],n,fx[5]={0,-1,0,1,0},fy[5]={0,0,1,0,-1};
void bfs()
{
    int h=0,t=1,x[10001],y[10001],xx,yy;
    x[1]=1;y[1]=1;
    while (h<t)
    {
        ++h;
        for (int i=1;i<=4;i++)
        {
            xx=x[h]+fx[i];yy=y[h]+fy[i];
            if (xx>=0&&xx<=n+1&&yy>=0&&yy<=n+1&&a[xx][yy]==0)
            {
                a[xx][yy]=3;
                ++t;
                x[t]=xx;y[t]=yy;
            }
        }
    }
}
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
        cin >>a[i][j];
    bfs ();
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
          if (a[i][j]==3)cout <<0<<' ';
          else if (a[i][j]==0)cout <<2<<' ';
          else cout <<1<<' ';
          cout <<endl;
    }
    return 0;
}

