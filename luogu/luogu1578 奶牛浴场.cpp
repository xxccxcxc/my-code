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
int xx,yy,n;
int ans=0;
struct dian
{
    int x,y;
}a[5005];
bool cmp1(dian t1,dian t2)
{
    return t1.x<t2.x;
}
bool cmp2(dian t1,dian t2)
{
    return t1.y<t2.y;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >>xx>>yy>>n;
    a[1].x=0;a[1].y=0;
    a[2].x=xx;a[2].y=0;
    a[3].x=0;a[3].y=yy;
    a[4].x=xx;a[4].y=yy;
    n+=4;
    for (int i=5;i<=n;i++)cin >>a[i].x>>a[i].y;
    sort (a+1,a+n+1,cmp1);
    for (int i=2;i<=n;i++)ans=max(ans,(a[i].x-a[i-1].x)*yy);
    sort (a+1,a+n+1,cmp2);
    //cout <<ans<<endl;
    for (int i=1;i<=n;i++)
    {
        int up=0,down=xx;
        for (int j=i+1;j<=n;j++)
        {
            if (a[j].x<=up||a[j].x>=down)continue;
            ans=max(ans,(down-up)*(a[j].y-a[i].y));
            if (a[j].x<a[i].x)up=a[j].x;
            if (a[j].x>a[i].x)down=a[j].x;
            if (a[j].x==a[i].x){up=down=0;break;}
        }
        ans=max(ans,(down-up)*(yy-a[i].y));
    }
    //cout <<ans<<endl;
    for (int i=n;i>=1;i--)
    {
        int up=0,down=xx;
        for (int j=i-1;j>=1;j--)
        {
            if (a[j].x<=up||a[j].x>=down)continue;
            ans=max(ans,(down-up)*(a[i].y-a[j].y));
            if (a[j].x<a[i].x)up=a[j].x;
            if (a[j].x>a[i].x)down=a[j].x;
            if (a[j].x==a[i].x){up=down=0;break;}
        }
        ans=max(ans,(down-up)*(a[i].y));
    }
    cout <<ans<<endl;
    return 0;
}

