#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
bool a[10000][10000]={0};
void hb(int x,int y)
{
    for (int i=x-2;i<=x+2;i++)
      a[i][y]=1;
    for (int i=y-2;i<=y+2;i++)
      a[x][i]=1;
    a[x-1][y-1]=a[x-1][y+1]=a[x+1][y-1]=a[x+1][y+1]=1;
}
void ys(int x,int y)
{
    for (int i=x-2;i<=x+2;i++)
      for (int j=y-2;j<=y+2;j++)
        a[i][j]=1;
}
int main()
{
    int n,h,y,xx,yy,s=0;
    cin >>n>>h>>y;
    for (int i=1;i<=h;i++)
    {
        cin >>xx>>yy;
        hb(xx+2,yy+2);
    }
    for (int i=1;i<=y;i++)
    {
        cin >>xx>>yy;
        ys(xx+2,yy+2);
    }
    for (int i=3;i<=n+2;i++)
      for (int j=3;j<=n+2;j++)
        if (!a[i][j])
          ++s;
    cout <<s;
    return 0;
}
