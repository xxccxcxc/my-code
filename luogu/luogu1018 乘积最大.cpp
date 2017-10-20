#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
long long n,m,a[11],b[11][11],f[11][7];
int qjs(int t1,int t2)
{
    int t3=0;
    for (int k=t1;k<=t2;k++)t3=t3*10+a[k];
    return t3;
}
int main()
{
    string s;
    cin >>n>>m>>s;
    for (int i=1;i<=n;i++)a[i]=s[i-1]-'0';
    for (int i=1;i<=n;i++)
      for (int j=i;j<=n;j++)
        b[i][j]=qjs(i,j);
    for (int i=1;i<=n;i++)f[i][0]=b[1][i];
    for (int k=1;k<=m;k++)
      for (int i=k+1;i<=n;i++)
        for (int j=k;j<i;j++)
          f[i][k]=max(f[i][k],f[j][k-1]*b[j+1][i]);
    cout <<f[n][m];
    return 0;
}

