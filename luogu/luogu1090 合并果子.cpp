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
int n,a[10005],ans,dsize,t;
void put(int x)
{
    a[++dsize]=x;
    int now=dsize,next;
    while (now>1)
    {
        next=now>>1;
        if (a[now]>=a[next])return;
        swap(a[now],a[next]);
        now=next;
    }
}
int get()
{
    int ret=a[1];a[1]=a[dsize--];
    int now=1,next;
    while ((now<<1)<=dsize)
    {
        next=now<<1;
        if (next<dsize&&a[next]>a[next+1])++next;
        if (a[now]<=a[next])return ret;
        swap(a[now],a[next]);now=next;
    }
    return ret;
}
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++){cin >>t;put(t);}
    for (int i=1;i<n;i++)
    {
        int t1=get(),t2=get();
        ans+=t1+t2;
        put(t1+t2);
    }
    cout <<ans;
    return 0;
}


