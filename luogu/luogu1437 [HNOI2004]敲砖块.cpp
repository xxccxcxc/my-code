#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
using namespace std;
int main()
{
    int n,m,a[60][60],f[60][60][1300]={0};
    cin >>n>>m;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n-i+1;j++)
        cin >>a[i][j];
    for (int i=n;i>=1;i--)
      for (int j=0;j<=n-i+1;j++)
        for (int k=2*j-1;k<=m;k++)
        {
            for (int l=j-1;l<=n-i+1;l++)
              if (l>=0)f[i][j][k]=max(f[i][j][k],f[i+1][l][k-j]);
            for (int l=1;l<=j;l++)
              f[i][j][k]+=a[l][i];
        }
    int ans=0;
    for (int i=1;i<=n;i++)
      for (int j=0;j<=n-i+1;j++)
        ans=max(ans,f[i][j][m]);
    cout <<ans;
    return 0;
}
