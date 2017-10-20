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
    int n,m,w[10001],c[10001],f[100001]={0};
    cin >>m>>n;
    for (int i=1;i<=n;i++)cin >>w[i]>>c[i];
    for (int i=1;i<=n;i++)
      for (int j=w[i];j<=m;j++)
        f[j]=max(f[j],f[j-w[i]]+c[i]);
    cout <<f[m];
    return 0;
}

