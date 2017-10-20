#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#define mo 10007
using namespace std;
int a,b,k,n,m,yh[1005][1005],ans;
int main()
{
    cin >>a>>b>>k>>n>>m;
    a%=mo;b%=mo;
    yh[0][0]=yh[1][0]=yh[1][1]=1;
    for (int i=2;i<=k;i++)
    {
        yh[i][0]=yh[i][i]=1;
        for (int j=1;j<i;j++)
          yh[i][j]=(yh[i-1][j-1]+yh[i-1][j])%mo;
    }
    ans=yh[k][n];
    for (int i=1;i<=n;i++)ans=(ans*a)%mo;
    for (int i=1;i<=m;i++)ans=(ans*b)%mo;
    cout <<ans;
    return 0;
}
