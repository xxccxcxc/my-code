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
int n,a[100005],lc[100005],rc[100005],t,b[100005],s,f[100005],tt;
void zx(int x)
{
    if (lc[x])zx(lc[x]);
    b[++t]=a[x];//cout <<x<<' ';
    if (rc[x])zx(rc[x]);
}
int ef(int x)
{
    int l=1,r=tt,mid;
    while (l<r)
    {
        mid=(l+r)/2;
        if (f[mid-1]<=x&&x<f[mid])return mid;
        if (x<f[mid-1])r=mid-1;
        else l=mid+1;
    }
}
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)scanf ("%d",&a[i]);
    for (int i=2;i<=n;i++)
    {
        int r1,r2;
        cin >>r1>>r2;
        if (r2==0)lc[r1]=i;
        else rc[r1]=i;
    }
    zx(1);
    for (int i=1;i<=n;i++){b[i]-=i;f[i]=0x7fffffff;}
    //for (int i=1;i<=n;i++)cout <<b[i]<<' ';cout <<endl;
    tt=0;memset (f,0x7f,sizeof(f));f[0]=-0x7fffffff;
    for (int i=1;i<=n;i++)
    {
        if (b[i]>=f[tt])f[++tt]=b[i];
        else f[ef(b[i])]=b[i];
    }
    //for (int i=1;i<=tt;i++)cout <<f[i]<<' ';cout <<endl;
    cout <<n-tt;
    return 0;
}

