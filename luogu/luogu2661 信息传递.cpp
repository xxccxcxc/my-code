#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#define mo 10007
using namespace std;
int n,a[200005],p[200005],t,ans=0x7fffffff;
void dfs(int x)
{
    if (p[x]==-1)return;
    if (p[x]>0)ans=min(ans,t-p[x]+1);
    else
    {
        p[x]=++t;
        dfs(a[x]);
    }
    p[x]=-1;
}
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)scanf ("%d",&a[i]);
    for (int i=1;i<=n;i++)
      if (p[i]==0)
      {
          t=0;
          dfs(i);
      }
    cout <<ans;
    return 0;
}
