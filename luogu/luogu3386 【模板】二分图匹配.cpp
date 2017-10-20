#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
int n,m,e,b[1005];
bool a[1005][1005],p[1005];
bool dfs(int u)
{
    for (int v=1;v<=m;v++)
    {
        if (a[u][v]&&!p[v])
        {
            p[v]=1;
            if (!b[v]||dfs(b[v]))
            {
                b[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int pp()
{
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        memset (p,0,sizeof(p));
        if (dfs(i))++ans;
    }
    return ans;
}
int main()
{
    scanf ("%d%d%d",&n,&m,&e);
    for (int i=1;i<=e;i++)
    {
        int t1,t2;
        scanf ("%d%d",&t1,&t2);
        if (t2<=m)a[t1][t2]=1; 
    }
    printf ("%d",pp());
    return 0;
}


