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
    int n,a[201]={0},f[201][201]={0},maxx=0;
    cin >>n;
    for (int i=1;i<=n;i++)cin >>a[i];
    for (int i=n+1;i<=n+n;i++)a[i]=a[i-n];
    for (int l=1;l<=n;l++)
    {
        memset (f,0,sizeof(f));
        for (int i=l+n-1;i>=l;i--)
          for (int j=i+1;j<=l+n-1;j++)
            for (int k=i;k<j;k++)
              f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+a[i]*a[k+1]*a[j+1]);
        maxx=max(maxx,f[l][l+n-1]);
    }
    cout <<maxx;
    return 0;
}

