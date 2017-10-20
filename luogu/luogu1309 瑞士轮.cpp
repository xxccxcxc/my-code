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
int n,r,q,a[400001],b[400001],f[400001],s[400001];
bool cmp(int ta,int tb)
{
    if (f[ta]==f[tb])return ta<tb;
    return f[ta]>f[tb];
}
void gb()
{
    int z=1,y=n+1,t=0;
    while (z<=n&&y<=2*n)
    {
        if (f[b[z]]>f[b[y]])a[++t]=b[z++];
        else if (f[b[z]]<f[b[y]])a[++t]=b[y++];
        else
          if (b[z]<b[y])a[++t]=b[z++];
          else a[++t]=b[y++];
    }
    while (z<=n)a[++t]=b[z++];
    while (y<=2*n)a[++t]=b[y++];
}
int main()
{
    cin >>n>>r>>q;
    for (int i=1;i<=2*n;i++){scanf ("%d",&f[i]);a[i]=i;}
    for (int i=1;i<=2*n;i++)scanf ("%d",&s[i]);
    sort (a+1,a+2*n+1,cmp);
    //for (int i=1;i<=2*n;i++)cout <<a[i]<<' ';
    for (int i=1;i<=r;i++)
    {
        int t1=0,t2=n;
        for (int j=1;j<=2*n;j+=2)
        {
            if (s[a[j]]>s[a[j+1]])
            {
                ++f[a[j]];
                b[++t1]=a[j];
                b[++t2]=a[j+1];
            }
            else
            {
                ++f[a[j+1]];
                b[++t1]=a[j+1];
                b[++t2]=a[j];
            }
        }
        gb();
    }
    cout <<a[q];
    return 0;
}

