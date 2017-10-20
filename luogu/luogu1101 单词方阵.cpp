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
int fx[9]={0,-1,0,1,1,1,0,-1,-1},fy[9]={0,1,1,1,0,-1,-1,-1,0};
string a[101];
int n;
bool p[101][101];
char pd[8]={'.','y','i','z','h','o','n','g'};
void dfs(int x,int y,int c,int fxx)
{
    int xx,yy;
    if (c==1)
    {
        for (int i=1;i<=8;i++)
        {
            xx=x+fx[i];
            yy=y+fy[i];
            if (xx>=1&&xx<=n&&yy>=0&&yy<n&&a[xx][yy]=='i')dfs (xx,yy,2,i);
        }
    }
    else if (c<7)
    {
        xx=x+fx[fxx];
        yy=y+fy[fxx];
        if (xx>=1&&xx<=n&&yy>=0&&yy<n&&a[xx][yy]==pd[c+1])dfs (xx,yy,c+1,fxx);
    }
    else
    {
        p[x][y]=1;
        for (int i=1;i<=6;i++){x-=fx[fxx];y-=fy[fxx];p[x][y]=1;}
    }
}
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)cin >>a[i];
    for (int i=1;i<=n;i++)
      for (int j=0;j<n;j++)
        if (a[i][j]=='y')
          dfs(i,j,1,0);
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<n;j++)
          if (p[i][j])
            cout <<a[i][j];
          else cout <<'*';
        cout <<endl;
    }
    return 0;
}

