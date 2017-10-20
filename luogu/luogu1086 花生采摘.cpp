#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
struct hs{
    int x,y,z;
}a[401];
int main()
{
    int m,n,sj,t,tt=0,s=0,xx=0,yy;
    cin >>m>>n>>sj;
    for (int i=1;i<=m;i++)
      for (int j=1;j<=n;j++)
      {
          cin >>t;
          if (t){++tt;a[tt].x=i;a[tt].y=j;a[tt].z=t;}
      }
    for (int i=1;i<tt;i++)
      for (int j=1;j<=tt;j++)
      {
          if (a[j].z<a[j+1].z)
          {
              t=a[j].x;a[j].x=a[j+1].x;a[j+1].x=t;
              t=a[j].y;a[j].y=a[j+1].y;a[j+1].y=t;
              t=a[j].z;a[j].z=a[j+1].z;a[j+1].z=t;
          }
      }
    yy=a[1].y;
    for (int i=1;i<=tt;i++)
    {
        sj-=abs(xx-a[i].x)+abs(yy-a[i].y);
        xx=a[i].x;yy=a[i].y;
        if (xx>=sj)break;
        s+=a[i].z;--sj;
    }
    cout <<s;
    return 0;
}
