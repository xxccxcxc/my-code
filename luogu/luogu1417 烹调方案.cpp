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
long long n,m,f[100001],maxx=0;
struct zun
{
    long long a,b,c;
}d[51];
bool cmp(zun t1,zun t2)
{
    return t2.c*t1.b>t1.c*t2.b;
}
int main()
{
    scanf ("%d%d",&m,&n);
    for (int i=1;i<=n;i++)scanf ("%d",&d[i].a);
    for (int i=1;i<=n;i++)scanf ("%d",&d[i].b);
    for (int i=1;i<=n;i++)scanf ("%d",&d[i].c);
    sort (d+1,d+n+1,cmp);
    for (int i=1;i<=n;i++)
      for (int j=m;j>=d[i].c;j--)
        f[j]=max(f[j],f[j-d[i].c]+d[i].a-j*d[i].b);
    for (int i=1;i<=m;i++)maxx=max(maxx,f[i]);
    cout <<maxx;
    return 0;
}

