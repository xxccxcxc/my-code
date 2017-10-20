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
int a[300001],b[300001],n,t,k,s,c[300001],m,x;  
int ef(int tt)  
{  
    int l=1,r=t,mid;  
    while (l<r)  
    {  
        mid=(l+r)/2;  
        if (tt>b[mid-1]&&tt<b[mid])return mid;  
        else if (b[mid]<tt)l=mid+1;  
        else r=mid-1;  
    }  
    return l;  
}  
int main()  
{  
    cin >>n>>k;  
    for (int i=1;i<=n;i++)scanf ("%d",&c[i]);  
    for (int i=1;i<k;i++)if (c[i]<c[k])a[++m]=c[i];  
    a[++m]=c[k];x=m;  
    for (int i=k+1;i<=n;i++)if (c[i]>c[k])a[++m]=c[i];  
    b[0]=-2147483647;  
    for (int i=1;i<x;i++)  
    {  
        if (a[i]>b[t])b[++t]=a[i];  
        else b[ef(a[i])]=a[i];  
    }  
    s=t;  
    t=0;  
    for (int i=1;i<=n;i++)b[i]=0;  
    for (int i=x+1;i<=m;i++)  
    {  
        if (a[i]>b[t])b[++t]=a[i];  
        else b[ef(a[i])]=a[i];  
    }  
    cout <<s+t+1;  
    return 0;  
}  
