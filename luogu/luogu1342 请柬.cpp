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
typedef long long ll;
using namespace std;
struct edge
{
    int to,next;
    ll w;
}a[2000005][2];
int head[2000005][2];
int n,m;
bool vis[2000005][2];
ll s[2000005][2];
queue <int> q[2];
int main()
{
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int r1,r2;ll r3;
        scanf ("%d%d%lld",&r1,&r2,&r3);
        a[i][0].w=r3;a[i][0].to=r2;a[i][0].next=head[r1][0];head[r1][0]=i;
        a[i][1].w=r3;a[i][1].to=r1;a[i][1].next=head[r2][1];head[r2][1]=i;
    }
    memset (s,0x7f,sizeof(s));
    for (int k=0;k<=1;k++)
    {
        s[1][k]=0;
        q[k].push(1);
        while (!q[k].empty())
        {
            int u=q[k].front();q[k].pop();vis[u][k]=0;
            int tt=head[u][k];
            while (tt!=0)
            {
                edge now=a[tt][k];
                if (s[now.to][k]>s[u][k]+now.w)
                {
                    s[now.to][k]=s[u][k]+now.w;
                    if (!vis[now.to][k])
                    {
                        vis[now.to][k]=1;
                        q[k].push(now.to);
                    }
                }
                tt=now.next;
            }
        }
    }
    ll ans=0;
    for (int i=2;i<=n;i++)
      ans+=s[i][0]+s[i][1];
    printf ("%lld",ans);
    return 0;
}

