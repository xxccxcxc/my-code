#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
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
using namespace std;
struct node{
    int x,y,t;
}a[100005];
int n,m,fa[1005];
bool cmp(node t1,node t2)
{
    return t1.t<t2.t;
}
int find(int tt)
{
    if (fa[tt]!=tt)fa[tt]=find(fa[tt]);
    return fa[tt];
}
void unionn(int t1,int t2)
{
    fa[t2]=t1;
}
bool pd()
{
    for (int i=2;i<=n;i++)
      if (find(fa[i])!=find(fa[1]))return 0;
    return 1;
}
int main()
{
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
      scanf ("%d%d%d",&a[i].x,&a[i].y,&a[i].t);
    sort (a+1,a+m+1,cmp);
    //for (int i=1;i<=n;i++)cout <<endl<<a[i].x<<' '<<a[i].y<<' '<<a[i].t<<endl;
    for (int i=1;i<=n;i++)fa[i]=i;
    for (int i=1;i<=m;i++)
    {
        int f1=find(a[i].x),f2=find(a[i].y);
        if (f1!=f2)unionn(f1,f2);
        if (pd()){cout <<a[i].t;return 0;}
        //for (int i=1;i<=n;i++)cout <<fa[i]<<' ';
    }
    cout <<-1;
    return 0;
}

