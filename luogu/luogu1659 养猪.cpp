#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
using namespace std;
struct pig
{
    int a,b;
}p[1005];
bool cmp(pig t1,pig t2)
{
    return t1.b>t2.b;
}
int main()
{
    //freopen ("pig.in","r",stdin);
    //freopen ("pig.out","w",stdout);
    int n,m,f[1005]={0};
    cin >>n>>m;
    for (int i=1;i<=n;i++)cin >>p[i].a;
    for (int i=1;i<=n;i++)cin >>p[i].b;
    sort (p+1,p+n+1,cmp);
    for (int i=1;i<=n;i++)
      for (int j=m;j>=1;j--)
        f[j]=max(f[j],f[j-1]+max(p[i].a-p[i].b*(j-1),0));
    int ans=0;
    for (int i=1;i<=m;i++)ans=max(ans,f[i]);
    cout <<ans;
    return 0;
}

