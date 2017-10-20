#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
using namespace std;
int n,m;
int fa[1005],a[1005][1005];
int find(int x)
{
    int t=x;
    while (fa[t]!=t)t=fa[t];
    return t;
}
void unionn(int x,int y)
{
    int fx=find(x),fy=find(y);
    fa[fx]=fy;
}
int main()
{
    cin >>n>>m;
    int z,x,y,ans=0;
    for (int i=1;i<=n;i++)fa[i]=i;
    for (int i=1;i<=m;i++)
    {
        cin >>z>>x>>y;
        if (!z)unionn(x,y);
        else
        {
            for (int j=1;j<=a[x][0];j++)
              unionn(a[x][j],y);
            for (int j=1;j<=a[y][0];j++)
              unionn(x,a[y][j]);
            a[x][++a[x][0]]=y;
            a[y][++a[y][0]]=x;
        }
    }
    for (int i=1;i<=n;i++)
      if (fa[i]==i)++ans;
    cout <<ans;
    return 0;
}

