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
struct node{
    int x,y,z;
}a[20005];
int n,m,s,t,tt;
int fa[10005];
bool cmp(node t1,node t2)
{
    return t1.z<t2.z;
}
int find(int d)
{
    if (fa[d]!=d)fa[d]=find(fa[d]);
    return fa[d];
}
int main()
{
    cin >>n>>m>>s>>t;
    for (int i=1;i<=m;i++)
      cin >>a[i].x>>a[i].y>>a[i].z;
    sort (a+1,a+m+1,cmp);
    for (int i=1;i<=n;i++)fa[i]=i;
    //cout <<n<<' '<<m<<' '<<s<<' '<<t<<endl;
    //for (int i=1;i<=m;i++)cout <<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<endl;
    for (int i=1;i<=m;i++)
    {
        int ta=find(a[i].x),tb=find(a[i].y);
        //cout <<a[i].x<<' '<<ta<<' '<<a[i].y<<' '<<tb<<endl;
        if (ta!=tb){fa[ta]=tb;++tt;}
        if (tt==n-1||find(s)==find(t)){cout <<a[i].z;break;}
    }
    return 0;
}
