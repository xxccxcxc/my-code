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
    int n,a[101],b[101],c[101],s;
    cin >>n;
    for (int i=1;i<=n;i++)cin >>a[i];
    for (int i=1;i<=n;i++)
    {
        b[i]=1;
        for (int j=i-1;j>=1;j--)
          if (a[i]>a[j]&&b[j]>=b[i])
            b[i]=b[j]+1;
    }
    for (int i=n;i>=1;i--)
    {
        c[i]=1;
        for (int j=i+1;j<=n;j++)
          if (a[i]>a[j]&&c[j]>=c[i])
            c[i]=c[j]+1;
    }
    s=b[1]+c[1]-1;
    for (int i=1;i<=n;i++)s=max(s,b[i]+c[i]-1);
    cout <<n-s;
    return 0;
}

