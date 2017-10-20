#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
using namespace std;
int n,m,ans,t;
struct ren{
    int p,a;
}s[5001];
bool cmp(ren ta,ren tb)
{
    return ta.p<tb.p;
}
int main()
{
    cin >>n>>m;
    for (int i=1;i<=m;i++)cin >>s[i].p>>s[i].a;
    sort(s+1,s+m+1,cmp);
    for (int i=1;i<=m;i++)
    {
        t=min(n,s[i].a);
        ans+=t*s[i].p;
        n-=t;
        if (!n)break;
    }
    cout <<ans;
    return 0;
}

