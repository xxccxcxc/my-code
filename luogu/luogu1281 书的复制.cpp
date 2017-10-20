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
    int m,k,a[501],f[501][501]={0},s[501]={0},t=0,b[501]={0},tt=0;
    cin >>m>>k;
    for (int i=1;i<=m;i++){cin >>a[i];s[i]=s[i-1]+a[i];}
    for (int i=1;i<=m;i++)
      for (int j=2;j<=k;j++)
        f[i][j]=0x7fffffff;
    for (int i=1;i<=m;i++)f[i][1]=s[i];
    for (int i=1;i<=m;i++)
      for (int j=2;j<=i;j++)
        for (int l=j-1;l<i;l++)
          f[i][j]=min(f[i][j],max(f[l][j-1],s[i]-s[l]));
    if (f[m][k]==0)return 0;
    for (int i=m;i>=1;i--)
    {
        t+=a[i];
        if (t>f[m][k]){t=a[i];b[++tt]=i;}
    }
    cout <<1<<' ';
    for (int i=tt;i>=1;i--)cout <<b[i]<<endl<<b[i]+1<<' ';
    cout <<m;
    return 0;
}

