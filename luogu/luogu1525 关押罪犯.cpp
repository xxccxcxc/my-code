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
struct node
{
    int x,y,z;
}a[100005];
int fa[40005];
bool cmp(node t1,node t2)
{
    return t1.z>t2.z;
}
int find(int t)
{
    if (fa[t]!=t)fa[t]=find(fa[t]);
    return fa[t];
}
int main()
{
    int n,m;
    cin >>n>>m;
    for (int i=1;i<=m;i++)
      cin >>a[i].x>>a[i].y>>a[i].z;
    sort (a+1,a+m+1,cmp);
    for (int i=1;i<=2*n;i++)fa[i]=i;
    for (int i=1;i<=m;i++)
    {
        int t1=find(a[i].x),t2=find(a[i].y);
        if (find(a[i].x)==find(a[i].y)){cout <<a[i].z;return 0;}
        fa[t1]=find(a[i].y+n);fa[t2]=find(a[i].x+n);
    }
    cout <<0;
    return 0;
}
