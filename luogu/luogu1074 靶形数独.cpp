#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#define getfg(x,y) (x-1)/3*3+(y-1)/3+1
using namespace std;
const int fz[10][10]=
{{0},
{0,6,6,6,6,6,6,6,6,6},  
{0,6,7,7,7,7,7,7,7,6},  
{0,6,7,8,8,8,8,8,7,6},  
{0,6,7,8,9,9,9,8,7,6},  
{0,6,7,8,9,10,9,8,7,6},  
{0,6,7,8,9,9,9,8,7,6},  
{0,6,7,8,8,8,8,8,7,6},  
{0,6,7,7,7,7,7,7,7,6},  
{0,6,6,6,6,6,6,6,6,6}};
const int g[10][10]={
{0},
{0,1,1,1,2,2,2,3,3,3},
{0,1,1,1,2,2,2,3,3,3},
{0,1,1,1,2,2,2,3,3,3},
{0,4,4,4,5,5,5,6,6,6},
{0,4,4,4,5,5,5,6,6,6},
{0,4,4,4,5,5,5,6,6,6},
{0,7,7,7,8,8,8,9,9,9},
{0,7,7,7,8,8,8,9,9,9},
{0,7,7,7,8,8,8,9,9,9}};
int ans,cs;
int a[10][10];
bool ha[10][10],li[10][10],fg[10][10];
/*void xyg(int &x,int &y)
{
    int minn=100,xx,yy;
    for (int i=1;i<=9;i++)
      for (int j=1;j<=9;j++)
        if (!a[i][j])
        {
            int t=0;
            for (int k=1;k<=9;k++)
              if (!ha[i][k]&&!li[j][k]&&!fg[g[i][j]][k])
                ++t;
            if (t<minn){minn=t;xx=i;yy=j;}
        }
    if (minn==100)x=y=0;
    else {x=xx;y=yy;}
}
int jia()
{
    int s=0;
    for (int i=1;i<=9;i++)
      for (int j=1;j<=9;j++)
        s+=a[i][j]*fz[i][j];
    return s;
}*/
void dfs(int gs,int s)
{
    if (!gs){ans=max(ans,s);return;}
    int x=0,y=0,minn=100;
    for (int i=1;i<=9;i++)
      for (int j=1;j<=9;j++)
        if (!a[i][j])
        {
            int t=0;
            for (int k=1;k<=9;k++)
              if (!ha[i][k]&&!li[j][k]&&!fg[g[i][j]][k])
                ++t;
            if (t==0)return;
            if (t<minn){minn=t;x=i;y=j;}
            if (t==1)break;
        }
    if (minn==100)return;
    for (int i=9;i>=1;i--)
      if (!ha[x][i]&&!li[y][i]&&!fg[g[x][y]][i])
      {
          a[x][y]=i;
          ha[x][i]=li[y][i]=fg[g[x][y]][i]=true;
          dfs(gs-1,s+a[x][y]*fz[x][y]);
          a[x][y]=ha[x][i]=li[y][i]=fg[g[x][y]][i]=false;
      }
}
int main()
{
    int r;
    ans=-1;
    int gs=81,ss=0;
    for (int i=1;i<=9;i++)
      for (int j=1;j<=9;j++)
      {
          scanf ("%d",&a[i][j]);
          if (a[i][j])
          {
              --gs;
              ha[i][a[i][j]]=1;
              li[j][a[i][j]]=1;
              fg[getfg(i,j)][a[i][j]]=1;
              ss+=fz[i][j]*a[i][j];
          }
      }
    dfs(gs,ss);
    printf ("%d\n",ans);
    return 0;
}
