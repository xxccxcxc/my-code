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
int fx[5]={0,0,1,0,-1},fy[5]={0,1,0,-1,0};
struct c
{
    int g,x,y;
}b[10001];
int n,m,a[101][101],tt=0,maxx=1,xx,yy,f[101][101];
bool cmp(c t1,c t2)
{
    return a[t1.x][t1.y]<a[t2.x][t2.y];
} 
int main()
{
    cin >>n>>m;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
          cin >>a[i][j];
          ++tt;
          b[tt].x=i;
          b[tt].y=j;
      }
    sort (b+1,b+tt+1,cmp);
    for (int i=1;i<=n;i++)for (int j=1;j<=m;j++)f[i][j]=1;
    for (int i=2;i<=tt;i++)
    {
        for (int j=1;j<=4;j++)
        {
            xx=b[i].x+fx[j];
            yy=b[i].y+fy[j];
            if (xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[b[i].x][b[i].y]>a[xx][yy])
              f[b[i].x][b[i].y]=max(f[b[i].x][b[i].y],f[xx][yy]+1);
        }
        maxx=max(maxx,f[b[i].x][b[i].y]);
    }
    cout <<maxx;
    return 0;
}

