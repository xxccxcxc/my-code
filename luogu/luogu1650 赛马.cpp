#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
using namespace std;
int n,a[2005],b[2005],f[2005][2005];
int ff(int t1,int t2)
{
    if (a[t1]>b[t2])return 1;
    if (a[t1]==b[t2])return 0;
    return -1;
}
bool cmp(int t1,int t2)
{
    return t1>t2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >>n;
        for (int i=1;i<=n;i++)cin >>a[i];
        for (int i=1;i<=n;i++)cin >>b[i];
        sort (a+1,a+n+1,cmp);
        sort (b+1,b+n+1,cmp);
        for (int i=1;i<=n;i++)f[i][i]=ff(i,n);
        for (int k=n-1;k>0;k--)
          for (int i=1;i<=k;i++)
          {
              int j=i+(n-k);
              f[i][j]=max(f[i+1][j]+ff(i,k),f[i][j-1]+ff(j,k));
          }
        cout <<f[1][n]*200<<endl;
    return 0;
}

