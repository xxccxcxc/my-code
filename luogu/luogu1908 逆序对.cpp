#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
using namespace std;
int n,a[40005];
int gb(int l,int r)
{
    if (l==r)return 0;
    int mid=(l+r)/2,s=gb(l,mid)+gb(mid+1,r);
    int x=l,y=mid+1,t=0,b[40005];
    while (x<=mid&&y<=r)
    {
        if (a[x]<a[y])b[++t]=a[x++];
        else {b[++t]=a[y++];s+=mid-x+1;}
    }
    while (x<=mid)b[++t]=a[x++];
    while (y<=r)b[++t]=a[y++];
    for (int i=1;i<=t;i++)a[l+i-1]=b[i];
    return s;
}
int main()
{
    scanf ("%d",&n);
    for (int i=1;i<=n;i++)scanf ("%d",&a[i]);
    printf ("%d",gb(1,n));
    return 0;
}

