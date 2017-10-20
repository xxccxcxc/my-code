#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int n,m,a[101]={0},f[1001]={0};
    cin >>n>>m;
    for (int i=1;i<=n;i++)
      cin >>a[i];
    f[0]=1;
    for (int i=1;i<=n;i++)
      for (int j=m;j>=a[i];j--)
        f[j]+=f[j-a[i]];
    cout <<f[m];
    return 0;
}

