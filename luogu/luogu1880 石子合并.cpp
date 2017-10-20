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
    int n,f[101][101]={0},a[101]={0},b[101][101]={0},maxx=0,ff[101][101]={0},minn=0x7fffffff;
    cin >>n;
    for (int i=1;i<=n;i++)cin >>a[i];
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
          if (i<=j)for (int k=i;k<=j;k++)b[i][j]+=a[k];
          else for (int k=i;k<=j+n;k++)if (k<=n)b[i][j]+=a[k];else b[i][j]+=a[k-n];
      }
    for (int j=2;j<=n;j++)
      for (int i=1;i<=n;i++)
        for (int k=1;k<j;k++)
          f[i][j]=max(f[i][j],f[i][k]+f[(i+k-1)%n+1][j-k]+b[i][(i+j-2)%n+1]);
    for (int i=1;i<=n;i++)maxx=max(maxx,f[i][n]);
    for (int j=2;j<=n;j++)
      for (int i=1;i<=n;i++)
      {
          ff[i][j]=ff[i][1]+ff[(i%n)+1][j-1]+b[i][(i+j-2)%n+1];
          for (int k=2;k<j;k++)
            ff[i][j]=min(ff[i][j],ff[i][k]+ff[(i+k-1)%n+1][j-k]+b[i][(i+j-2)%n+1]);
      }
    for (int i=1;i<=n;i++)minn=min(minn,ff[i][n]);
    cout <<minn<<endl<<maxx;
    return 0;
}

