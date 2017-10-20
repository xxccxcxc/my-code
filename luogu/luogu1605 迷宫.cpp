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
int n,m,nn,sx,sy,ex,ey,sr1,sr2,a[6][6],ans;
void dfs(int x,int y)
{
    if (x==ex&&y==ey){++ans;return;}
    int xx,yy;
    for (int i=1;i<=4;i++)
    {
        xx=x+fx[i];
        yy=y+fy[i];
        if (xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]==0)
        {
            a[xx][yy]=1;
            dfs(xx,yy);
            a[xx][yy]=0;
        }
    }
}
int main()
{
    cin >>n>>m>>nn>>sx>>sy>>ex>>ey;
    for (int i=1;i<=nn;i++){cin >>sr1>>sr2;a[sr1][sr2]=1;}
    a[sx][sy]=1;
    dfs(sx,sy);
    cout <<ans;
    return 0;
}

