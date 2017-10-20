#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t=1,a[201],n,m,tt,s=0;
    cin >>n>>m;
    for (int i=1;i<=n;i++){a[i]=i;}
    for (int i=1;i<=m;i++)
    {
        tt=((i*i*i)%5)+1;
        if (t+tt>n){--i;t=1;continue;}
        t+=tt;--n;s=a[t];
        for (int j=t;j<=n;j++)a[j]=a[j+1];
    }
    cout <<s;
    return 0;
}
