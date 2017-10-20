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
#define mo 100003
using namespace std;
int n,m,b[200005],f[200005];
vector <int> a[200005];
queue <int> q;
int main()
{
    cin >>n>>m;
    for (int i=1;i<=m;i++)
    {
        int r1,r2;
        scanf ("%d%d",&r1,&r2);
        a[r1].push_back(r2);
        a[r2].push_back(r1);
    }
    q.push(1);f[1]=1;memset (b,0x7f,sizeof(b));b[1]=0;
    while (!q.empty())
    {
        int u=q.front();q.pop();
        for (int i=0;i<a[u].size();i++)
        {
            int v=a[u][i];
            if (b[v]==b[u]+1)f[v]=(f[v]+f[u])%mo;
            if (b[v]>b[u]+1){f[v]=f[u];b[v]=b[u]+1;q.push(v);}
        }
    }
    for (int i=1;i<=n;i++)printf ("%d\n",f[i]);
    return 0;
}

