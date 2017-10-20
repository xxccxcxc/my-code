#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int n,m,fx[13]={0,-2,-1,-1,-1,0,0,0,0,1,1,1,2},fy[13]={0,0,-1,0,1,-2,-1,1,2,-1,0,1,0},ans,t;
bool a[101][101];
void bfs(int kx,int ky)
{
    int d[10001][3],h=0,t=1,x,y;
    d[1][1]=kx;d[1][2]=ky;a[kx][ky]=0;
    ++ans;
    do
    {
        ++h;
        for (int i=1;i<=12;i++)
        {
            x=d[h][1]+fx[i];
            y=d[h][2]+fy[i];
            if (a[x][y]&&x>0&&x<=n&&y>0&&y<=m)
            {
                ++t;
                a[x][y]=0;
                d[t][1]=x;
                d[t][2]=y;
            }
        }
    }while (h<t);
}
int main()
{
    cin >>n>>m;
    string sr;
    for (int i=1;i<=n;i++)
    {
        cin >>sr;
        for (int j=1;j<=m;j++)
          a[i][j]=(sr[j-1]=='#');
    }
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        if (a[i][j])
          bfs (i,j);
    cout <<ans;
    return 0;
}

