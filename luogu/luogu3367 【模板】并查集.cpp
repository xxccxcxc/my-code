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
int fa[20005];
int find(int x)
{
    if (x!=fa[x])fa[x]=find(fa[x]);
    return fa[x];
}
void unionn(int x,int y)
{
    int fx=find(x),fy=find(y);
    fa[fx]=fy;
}
int main()
{
    int n,m;
    cin >>n>>m;
    for (int i=1;i<=n;i++)fa[i]=i;
    for (int i=1;i<=m;i++)
    {
        int p,x,y;
        cin >>p>>x>>y;
        if (p==1)unionn(x,y);
        else if (find(x)!=find(y))cout <<"N\n";
        else cout <<"Y\n";
    }
    return 0;
}


