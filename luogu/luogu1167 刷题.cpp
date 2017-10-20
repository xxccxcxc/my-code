#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
bool rn(int n)
{
    if (n%400==0)return 1;
    if (n%100==0)return 0;
    if (n%4==0)return 1;
    return 0;
}
int main()
{
    int nn,aa[5001],biao[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},ans=0;
    unsigned long long a=0,b=0;
    cin >>nn;
    for (int i=1;i<=nn;i++)cin >>aa[i];
    int n,y,r,s,f,n1,y1,r1,s1,f1;
    scanf ("%d-%d-%d-%d:%d",&n,&y,&r,&s,&f);
    scanf ("%d-%d-%d-%d:%d",&n1,&y1,&r1,&s1,&f1);
    for (int i=0;i<n;i++)if (!rn(i))a+=365*1440;else a+=366*1440;
    for (int i=0;i<n1;i++)if (!rn(i))b+=365*1440;else b+=366*1440;
    for (int i=1;i<y;i++)a+=biao[i]*1440;if (rn(n)&&y>=3)a+=1440;
    for (int i=1;i<y1;i++)b+=biao[i]*1440;if (rn(n1)&&y1>=3)b+=1440;
    a+=(r-1)*1440;b+=(r1-1)*1440;
    a+=s*60;b+=s1*60;
    a+=f;b+=f1;a=b-a;
    sort (aa+1,aa+1+nn);
    for (int i=1;i<=nn;i++)
    {
        if (a<aa[i])break;
        a-=aa[i];
        ++ans;
    }
    cout <<ans;
    return 0;
}

