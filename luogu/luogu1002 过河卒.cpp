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
    long long n,m,x,y,f[22][22]={0};
    cin >>n>>m>>x>>y;
    ++n;++m;++x;++y;
    f[0][1]=1;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        if (!(abs(x-i)+abs(y-j)==3&&i!=x&&j!=y||i==x&&j==y))
          f[i][j]=f[i-1][j]+f[i][j-1];
    cout <<f[n][m];
    return 0;
}//我只是看完标程以后不小心背下来了 

