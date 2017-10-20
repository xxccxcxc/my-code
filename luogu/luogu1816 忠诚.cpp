#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <utility>
using namespace std;
int a[200005]={0},f[200005][31]={0};
int main()
{
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);
    int n,m;
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;i++){scanf ("%d",&a[i]);f[i][0]=a[i];}
    for (int j=1;j<=log(n)/log(2);j++)
      for (int i=1;i<=n-(1<<j)+1;i++)
        f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf ("%d%d",&x,&y);
        int t=log(y-x+1)/log(2);
        printf ("%d ",min(f[x][t],f[y-(1<<t)+1][t]));
    }
    return 0;
}

