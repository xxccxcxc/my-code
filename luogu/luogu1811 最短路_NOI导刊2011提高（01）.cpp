#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <climits>
#include <utility>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#define ting system ("pause")
using namespace std;
int n,m,k;
vector <int> a[3005];
map <long long,bool> hash;
map <int,bool> hash1;
typedef pair<int,int> node;
queue <node> q;
bool vis[3005][3005];
int pre[3005][3005],dis[3005][3005],ans[3005];
long long kt(int t1,int t2,int t3)
{
    return (t1<<24)+(t2<<12)+t3;
}
int kt1(int t1,int t2)
{
    return (t1<<12)+t2;
}
void SPFA()
{
    memset (dis,0x7f,sizeof(dis));
    for (int i=0;i<a[1].size();i++)
    {
        q.push(make_pair(1,a[1][i]));
        dis[1][a[1][i]]=vis[1][a[1][i]]=1;
    }
    while (!q.empty())
    {
        node t=q.front();q.pop();
        int p=t.first,u=t.second;vis[p][u]=0;
        //cout <<p<<' '<<u<<endl;
        for (int i=0;i<a[u].size();i++)
        {
            int v=a[u][i];
            if (hash[kt(p,u,v)])continue;
            //cout <<p<<' '<<u<<' '<<v<<endl;
            if (dis[p][u]+1<dis[u][v])
            {
                dis[u][v]=dis[p][u]+1;
                pre[u][v]=p;
                if (!vis[u][v])
                {
                    vis[u][v]=1;
                    q.push(make_pair(u,v));
                }
            }
        }
    }
    int x=-1,y=n,tt=0;
    for (int i=1;i<n;i++)
      if (x==-1||dis[i][y]<dis[x][y])x=i;
    ans[++tt]=n;
    printf ("%d\n",dis[x][n]);
    //cout <<x<<' '<<y<<endl;
    while (x!=0)
    {
        ans[++tt]=x;
        int ttt=x;x=pre[x][y];y=ttt;
        //cout <<x<<' '<<y<<endl;
    }
    for (int i=tt;i>=1;i--)printf ("%d ",ans[i]);
}
bool init()
{
    scanf ("%d%d%d",&n,&m,&k);
    for (int i=1;i<=m;i++)
    {
        int r1,r2;
        scanf ("%d%d",&r1,&r2);
        a[r1].push_back(r2);
        a[r2].push_back(r1);
        hash1[kt1(r1,r2)]=hash1[kt1(r2,r1)]=1;
        if (r1==1&&r2==n||r1==n&&r2==1){printf ("1\n1 %d",n);return 0;}
    }
    for (int i=1;i<=k;i++)
    {
        int r1,r2,r3;
        scanf ("%d%d%d",&r1,&r2,&r3);
        hash[kt(r1,r2,r3)]=1;
    }
    //cout <<hash1[kt1(1,2)]<<' '<<hash1[kt1(2,4)]<<endl<<endl;
    for (int i=2;i<n;i++)
      if (hash1[kt1(1,i)]&&hash1[kt1(i,n)]&&!hash[kt(1,i,n)])
      {
            printf ("2\n1 %d %d",i,n);
            return 0;
      }
    return 1;
}
int main()
{
    //freopen ("path.in","r",stdin);
    //freopen ("path.out","w",stdout);
    if (init())SPFA();
    return 0;
}
/*
4 4 2 
1 2 
2 3 
3 4 
1 3 
1 2 3 
1 3 4 
*/

