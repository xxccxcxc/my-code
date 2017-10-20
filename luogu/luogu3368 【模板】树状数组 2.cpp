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
int n,m,a[500005],d[500005];
int lowbit(int x){return x&(-x);}
void add(int x,int y)
{
    while (x<=n)
    {
        a[x]+=y;
        x+=lowbit(x);
    }
}
int ask(int x)
{
    int ret=0;
    while (x)
    {
        ret+=a[x];
        x-=lowbit(x);
    }
    return ret;
}
int main()
{
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;i++){scanf ("%d",&d[i]);add(i,d[i]-d[i-1]);} 
    for (int i=1;i<=m;i++)
    {
        int p;
        scanf ("%d",&p);
        if (p==1)
        {
            int x,y,w;
            scanf ("%d%d%d",&x,&y,&w);
            add(x,w);add(y+1,-w);
        }
        else
        {
            int x;
            scanf("%d",&x);
            printf("%d\n",ask(x));
        }
    }
    return 0;
}
