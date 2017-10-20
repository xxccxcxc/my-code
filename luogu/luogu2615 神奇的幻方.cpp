#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
int main()
{
    int a[50][50]={0},n,x,y;
    cin >>n;
    a[1][n/2+1]=1;x=1;y=n/2+1;
    for (int i=2;i<=n*n;i++)
    {
        if (x==1&&y!=n){a[n][y+1]=i;x=n;++y;}
        else if (x!=1&&y==n){a[x-1][1]=i;--x;y=1;}
        else if (x==1&&y==n){a[x+1][y]=i;++x;}
        else if (!a[x-1][y+1]){a[x-1][y+1]=i;--x;++y;}
        else {a[x+1][y]=i;++x;}
        //cout <<i<<' '<<x<<' '<<y<<endl;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
          cout <<a[i][j]<<' ';
        cout <<endl;
    }
    return 0;
}
