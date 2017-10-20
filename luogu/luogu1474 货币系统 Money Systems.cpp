#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main()
{
    int n,m,w[26];
    long long f[10001]={0};
    f[0]=1;
    cin >>n>>m;
    for (int i=1;i<=n;i++)cin >>w[i];
    for (int i=1;i<=n;i++)
      for (int j=w[i];j<=m;j++)
        f[j]+=f[j-w[i]];
    cout <<f[m];
    return 0;
}

