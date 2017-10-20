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
#define MAXN 10000000
using namespace std;
bool p[MAXN+5];
int main()
{
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);
    int n,m;
    scanf ("%d%d",&n,&m);
    p[0]=p[1]=1;
    for (int i=2;i<=n;i++)
      if (!p[i])
        for (int j=i*2;j<=n;j+=i)
          p[j]=1;
    for (int i=1;i<=m;i++)
    {
        int t;
        scanf ("%d",&t);
        if (p[t])printf ("No\n");
        else printf ("Yes\n");
    }
    return 0;
}

