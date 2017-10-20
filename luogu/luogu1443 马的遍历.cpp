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
int fx[9]={0,-2,-1,1,2,2,1,-1,-2},fy[9]={0,1,2,2,1,-1,-2,-2,-1};
int a[201][201],h,t,x[100001],y[100001],c[100001],xx,yy,sx,sy,n,m;
bool p[201][201];
void bfs()
{
    h=0;t=1;
    x[1]=sx;y[1]=sy;
    p[sx][sy]=1;
    do
    {
        ++h;
        for (int i=1;i<=8;i++)
        {
            xx=x[h]+fx[i];
            yy=y[h]+fy[i];
            if (xx>=1&&xx<=n&&yy>=1&&yy<=m&&p[xx][yy]==0)
            {
                ++t;
                x[t]=xx;y[t]=yy;c[t]=c[h]+1;
                p[xx][yy]=1;a[xx][yy]=c[t];
            }
        }
    }while (h<t);
}
int main()
{
    cin >>n>>m>>sx>>sy;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        a[i][j]=-1;
    a[sx][sy]=0;
    bfs();
    for (int i=1;i<=n;i++) 
    {
        for (int j=1;j<=m;j++)
          printf ("%-5d",a[i][j]);
        cout <<endl;
    }
    return 0;
}

