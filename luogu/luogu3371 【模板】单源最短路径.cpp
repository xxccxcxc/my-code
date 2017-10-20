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
#define MAXN 10000
#define MAXM 500000
using namespace std;
struct edge
{
    int to,next,w;
}a[MAXM+5];
struct node
{
    int d,w;
    node(){d=w=0;}
    node(int dd,int ww){d=dd;w=ww;}
    bool operator < (const node &t1)const{return w>t1.w;}
};
int n,m,st,t;
int head[MAXN+5],f[MAXN+5];
bool vis[MAXN+5];
void add(int x,int y,int z)
{
    a[++t].w=z;
    a[t].to=y;
    a[t].next=head[x];
    head[x]=t;
}
void dij()
{
    memset (f,127,sizeof(f));
    priority_queue <node> q;
    f[st]=0;vis[st]=1;q.push(node(st,0));
    int u=st;
    for (int i=1;i<n;i++)
    {
        for (int j=head[u];j;j=a[j].next)
        {
            int v=a[j].to,s=a[j].w;
            if (!vis[v]&&f[u]+s<f[v])
            {
                f[v]=f[u]+s;
                q.push(node(v,f[v]));
            }
        }
        while (!q.empty()&&vis[q.top().d])q.pop();
        if (q.empty())return;
        u=q.top().d;vis[u]=1;q.pop();
    }
}
int main()
{
    scanf ("%d%d%d",&n,&m,&st);
    for (int i=1;i<=m;i++)
    {
        int r1,r2,r3;
        scanf ("%d%d%d",&r1,&r2,&r3);
        add(r1,r2,r3);
    }
    dij();
    for (int i=1;i<=n;i++)
      if (f[i]>200000000)printf ("2147483647 ");
      else printf ("%d ",f[i]);
    return 0;
}
