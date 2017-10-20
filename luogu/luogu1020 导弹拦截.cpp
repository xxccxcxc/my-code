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
    int a[1001]={0},b[1001]={0},g[1001]={0},t=0,m=0,n;
    while (cin >>a[++t])
    {
        for (int i=1;i<=t-1;i++)
          if (a[i]>=a[t])
            if (b[i]>b[t])b[t]=b[i];
        ++b[t];
        if (b[t]>m)m=b[t];
        int x=0;
        for (int i=1;i<=n;i++)
          if (g[i]>=a[t])
            if (!x)x=i;
            else if (g[i]<g[x])x=i;
        if (x==0)x=++n;
        g[x]=a[t];
    }
    cout <<m<<endl<<n;
    return 0;
}

