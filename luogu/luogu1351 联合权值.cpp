#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#define mo 10007
using namespace std;
int n;
long long x[200005],y[200005],w[200005],s[200005],m1[200005],m2[200005],s1,s2;
void ycl(int u,int v)
{
    if (w[v]>m1[u]){m2[u]=m1[u];m1[u]=w[v];}
    else if (w[v]>m2[u])m2[u]=w[v];
}
int main()
{
    cin >>n;
    for (int i=1;i<n;i++)cin >>x[i]>>y[i];
    for (int i=1;i<=n;i++)cin >>w[i];
    for (int i=1;i<n;i++)
    {
        s[x[i]]+=w[y[i]];s[y[i]]+=w[x[i]];
        ycl(x[i],y[i]);ycl(y[i],x[i]);
    }
    for (int i=1;i<=n;i++)s1=max(s1,m1[i]*m2[i]);
    for (int i=1;i<n;i++)
      s2=(s2+(w[x[i]]*(s[y[i]]-w[x[i]]))%mo+(w[y[i]]*(s[x[i]]-w[y[i]]))%mo)%mo;
    cout <<s1<<' '<<s2;
    return 0;
}
