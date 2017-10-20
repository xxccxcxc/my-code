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
int main()
{
    int h,p,a[101][101]={0},f[101][101]={0},c[101][101]={0},maxx;
    cin >>h>>p;
    for (int i=1;i<=h;i++)
      for (int j=1;j<=p;j++)
        cin >>a[i][j];
    for (int i=1;i<=h;i++)
      for (int j=1;j<=p-h+1;j++)
        a[i][j]=a[i][j+i-1];
    p-=(h-1);
    for (int i=1;i<=p;i++)f[h][i]=a[h][i];
    for (int i=h-1;i>=1;i--)
      for (int j=1;j<=p;j++)
      {
          maxx=j;
          for (int k=j+1;k<=p;k++)
            if (f[i+1][k]>f[i+1][maxx])
              maxx=k;
          f[i][j]=f[i+1][maxx]+a[i][j];
          c[i][j]=maxx;
      }
    maxx=1;
    for (int i=2;i<=p;i++)
      if (f[1][i]>f[1][maxx])
        maxx=i;
    cout <<f[1][maxx]<<endl<<maxx<<' ';
    for (int i=1;i<h;i++)
    {
        maxx=c[i][maxx];
        cout <<maxx+i<<' ';
    }
    return 0;
}

