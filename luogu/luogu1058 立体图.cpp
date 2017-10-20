#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
int n,m,r,c,b[55][55];
char a[1000][1000];
void draw(int x,int y)
{
    a[x][y]='+';
    a[x][y+1]='-';
    a[x][y+2]='-';
    a[x][y+3]='-';
    a[x][y+4]='+';
    a[x-1][y]='|';
    a[x-1][y+1]=' ';
    a[x-1][y+2]=' ';
    a[x-1][y+3]=' ';
    a[x-1][y+4]='|';
    a[x-1][y+5]='/';
    a[x-2][y]='|';
    a[x-2][y+1]=' ';
    a[x-2][y+2]=' ';
    a[x-2][y+3]=' ';
    a[x-2][y+4]='|';
    a[x-2][y+5]=' ';
    a[x-2][y+6]='+';
    a[x-3][y]='+';
    a[x-3][y+1]='-';
    a[x-3][y+2]='-';
    a[x-3][y+3]='-';
    a[x-3][y+4]='+';
    a[x-3][y+5]=' ';
    a[x-3][y+6]='|';
    a[x-4][y+1]='/';
    a[x-4][y+2]=' ';
    a[x-4][y+3]=' ';
    a[x-4][y+4]=' ';
    a[x-4][y+5]='/';
    a[x-4][y+6]='|';
    a[x-5][y+2]='+';
    a[x-5][y+3]='-';
    a[x-5][y+4]='-';
    a[x-5][y+5]='-';
    a[x-5][y+6]='+';
}
int main()
{
    cin >>n>>m;
    c=n*2+m*4+1;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
          cin >>b[i][j];
          r=max(r,(n-i+1)*2+b[i][j]*3+1); 
      }
    for (int i=1;i<=r;i++)
      for (int j=1;j<=c;j++)
        a[i][j]='.';
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        for (int k=1;k<=b[i][j];k++)
          draw(r-(n-i)*2-(k-1)*3,(n-i)*2+(j-1)*4+1);
    for (int i=1;i<=r;i++)
    {
        for (int j=1;j<=c;j++)
          cout <<a[i][j];
        cout <<endl;
    }
}
