#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,a[101]={0},b[20001]={0},ans=0;
    cin >>n;
    for (int i=1;i<=n;i++){cin >>a[i];++b[a[i]];}
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
        while (a[i]!=a[j]&&b[a[i]+a[j]]>0)
        {
            ++ans;
            --b[a[i]+a[j]];
        }
    cout <<ans<<endl;
    return 0;
}

