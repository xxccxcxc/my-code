#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
int n,m,t,ttx,tty,a[20][20],s;
void dfs(int x,int y)
{
    if (x==n&&y==m){++s;return;}
    if (a[x+1][y])dfs (x+1,y);
    if (a[x][y+1])dfs (x,y+1);
}
int main()
{
    cin >>n>>m>>t;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        a[i][j]=1;
    for (int i=1;i<=t;i++)
    {
        cin >>ttx>>tty;
        a[ttx][tty]=0;
    }
    dfs (1,1);
    cout <<s;
    return 0;
}

