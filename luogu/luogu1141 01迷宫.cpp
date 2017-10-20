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
int fx[5]={0,-1,0,1,0},fy[5]={0,0,1,0,-1};
int n,m,a[1001][1001],lu[1001][1001],s[1000001],tt=0,sr1,sr2;
int h,t,dx[1000001],dy[1000001],xx,yy;
string sr;
void bfs(int x,int y)
{
    s[++tt]=1;
    h=0;t=1;
    dx[1]=x;dy[1]=y;
    lu[x][y]=tt;
    do
    {
        ++h;
        for (int i=1;i<=4;i++)
        {
            xx=dx[h]+fx[i];
            yy=dy[h]+fy[i];
            if (xx<1||xx>n||yy<1||yy>n)continue;
            if (a[xx][yy]!=a[dx[h]][dy[h]]&&lu[xx][yy]==0)
            {
                ++s[tt];
                lu[xx][yy]=tt;
                ++t;
                dx[t]=xx;
                dy[t]=yy;
            }
        }
    }while (h<t);
}
int main()
{
    cin >>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin >>sr;
        for (int j=1;j<=n;j++)
          a[i][j]=sr[j-1];
    }
    for (int i=1;i<=m;i++)
    {
        scanf ("%d%d",&sr1,&sr2);
        if (lu[sr1][sr2]==0)bfs(sr1,sr2);
        printf ("%d\n",s[lu[sr1][sr2]]);
    }
    return 0;
}

