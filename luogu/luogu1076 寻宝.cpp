#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int a[10001][101]={0},p[10001][101]={0},n,m,lt[10001]={0},t,ans=0,tt;
int main()
{
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
      for (int j=0;j<m;j++)
      {
          scanf ("%d%d",&p[i][j],&a[i][j]);
          lt[i]+=p[i][j];
      }
    scanf ("%d",&t);
    for (int i=1;i<=n;i++)
    {
        ans=(ans+a[i][t])%20123;
        tt=a[i][t]%lt[i];
        if (tt==0)tt+=lt[i];
        while (tt)
        {
            tt-=p[i][t];
            if (tt==0)break;
            ++t;
            if (t==m)t=0;
        }
    }
    printf ("%d",ans);
    return 0;
}

