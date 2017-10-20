#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
using namespace std;
int n,m,a[101],f[101]={1};
int main()
{
    cin >>n>>m;
    for (int i=1;i<=n;i++)cin >>a[i];
    for (int i=1;i<=n;i++)
      for (int j=m;j>=1;j--)
        for (int k=1;k<=j&&k<=a[i];k++)
          f[j]=(f[j]+f[j-k])%1000007;
    cout <<f[m];
    return 0;
}

