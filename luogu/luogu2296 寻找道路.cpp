#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
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
int n,m,st,ed;
bool p[10005],p1[10005],p2[10005],p3;
vector <int> zt[10005],ft[10005];
struct node{
    int d,b;
    node (int dd,int bb){d=dd;b=bb;}
};
queue <int> q1;
queue <node> q2;
int main()
{
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int r1,r2;
        scanf ("%d%d",&r1,&r2);
        zt[r1].push_back(r2);
        ft[r2].push_back(r1);
    }
    scanf ("%d%d",&st,&ed);
    q1.push(ed);p[ed]=p1[ed]=1;
    while (!q1.empty())
    {
        int t=q1.front();
        q1.pop();
        for (int i=0;i<ft[t].size();i++)
        {
            int tt=ft[t][i];
            if (!p[tt])
            {
                p[tt]=p1[tt]=1;
                q1.push(tt);
            }
        }
    }
    for (int i=1;i<=n;i++)
      if (!p[i])
        for (int j=0;j<ft[i].size();j++)
          p1[ft[i][j]]=0;
    q2.push(node(st,0));
    while (!q2.empty())
    {
        node t=q2.front();
        int t1=t.d;int t2=t.b;
        if (t1==ed){printf ("%d",t2);p3=1;break;}
        q2.pop();
        for (int i=0;i<zt[t1].size();i++)
        {
            int tt=zt[t1][i];
            if (p1[tt]&&!p2[tt])
            {
                p2[tt]=1;
                q2.push(node(tt,t2+1));
            }
        }
    }
    if (!p3)printf ("-1");
    return 0;
}
