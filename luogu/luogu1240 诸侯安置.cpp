#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
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
#define mo 504
using namespace std;
int main()
{
    int n,m,len[205]={0},f[205][205]={0};
    cin >>n>>m;
    n=n*2-1;
    if (m>n){cout <<0;return 0;}
    for (int i=1;i<n;i+=2)len[i]=len[i+1]=i;
    f[0][0]=1;
    len[n]=n;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=i&&j<=m;j++)
      {
            for (int k=0;k<i;k++)
              f[i][j]=(f[i][j]+f[k][j-1])%mo;
            f[i][j]=(f[i][j]*(len[i]-j+1))%mo;
      }
    int ans=0;
    for (int i=0;i<=n;i++)ans=(ans+f[i][m])%mo;
    cout <<ans;
    return 0;
}

