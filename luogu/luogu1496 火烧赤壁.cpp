#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <climits>
#include <map>
using namespace std;
struct tree{
    int x,y;
}a[20005];
bool cmp(tree t1,tree t2)
{
    return t1.x<t2.x;
}
int main()
{
    int n,h,t,ans=0;
    cin >>n;
    for (int i=1;i<=n;i++)cin >>a[i].x>>a[i].y;
    sort (a+1,a+n+1,cmp);
    h=a[1].x;t=a[1].y;
    for (int i=2;i<=n;i++)
    {
        if (a[i].x<=t)
         {
            h=min(h,a[i].x);
            t=max(t,a[i].y);
        }
        else
        {
            ans+=t-h;
            h=a[i].x;
            t=a[i].y;
        }
    }
    ans+=t-h;
    cout <<ans;
    return 0;
}


