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
int n,x[100],y[100],a[100][100],m,fa[100];
struct edge
{
    int u,v,dis;
}b[10000];
bool cmp(edge t1,edge t2)
{
    return t1.dis<t2.dis;
}
int find(int t)
{
    if (fa[t]!=t)return find(fa[t]);
    return t;
}
void unionn(int t1,int t2)
{
    int f1=find(t1),f2=find(t2);
    if (f1!=f2)fa[f1]=f2;
}
int main()
{
    //freopen ("ppg.in","r",stdin);
    //freopen ("ppg.ans","w",stdout);
    cin >>n;
    for (int i=1;i<=n;i++)cin >>x[i]>>y[i];
    for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
      {
            a[i][j]=a[j][i]=(abs(x[i]-x[j])+abs(y[i]-y[j])+1)/2;
            ++m;b[m].u=i;b[m].v=j;b[m].dis=a[i][j];
      }
    /*for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
          cout <<a[i][j]<<' ';
        cout <<endl;
    }*/
    sort (b+1,b+m+1,cmp);
    int t=0;
    for (int i=1;i<=n;i++)fa[i]=i;
    for (int i=1;i<=m;i++)
    {
        int t1=b[i].u,t2=b[i].v,t3=b[i].dis;
        if (find(t1)!=find(t2))
        {
            unionn(t1,t2);
            ++t;
            if (t==n-1){cout <<t3;break;}
        }
    }
    return 0;
}

