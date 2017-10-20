#include <algorithm>
#include <iostream>
#include <iomanip>
#include <climits>
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
    int n,k,a[101]={0},b[101]={0},f[101][101]={0},minn;
    cin >>n>>k;
    for (int i=2;i<=n;i++)
      for (int j=1;j<=n;j++)
        f[i][j]=2100000000;
    for (int i=1;i<=n;i++)cin >>a[i]>>b[i];
    for (int i=1;i<n;i++)
      for (int j=i+1;j<=n;j++)
        if (a[i]>a[j])
          {swap(a[i],a[j]);swap(b[i],b[j]);}
    for (int i=2;i<=n-k;i++)
      for (int j=1;j<=n;j++)
        for (int k=1;k<j;k++)
          {f[i][j]=min(f[i][j],f[i-1][k]+abs(b[j]-b[k]));/*cout <<i<<' '<<j<<' '<<k<<' '<<f[i-1][k]<<' '<<abs(b[j]-b[k])<<endl;*/}
    /*for (int i=1;i<=n-k;i++){
      for (int j=1;j<=n;j++)
        cout <<f[i][j]<<' ';cout <<endl;}*/
    minn=f[n-k][1];
    for (int i=2;i<=n;i++)minn=min(minn,f[n-k][i]);
    cout <<minn;
    return 0;
}

