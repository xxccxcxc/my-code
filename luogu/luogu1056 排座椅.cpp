#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    int m,n,h,s,d,x1,x2,y1,y2,max,t=0;
    cin >>m>>n>>h>>s>>d;
    int a[1001]={0},b[1001]={0},aa[1001],bb[1001];
    for (int i=1;i<=d;i++)
    {
        cin >>x1>>y1>>x2>>y2;
        if (x1==x2)++b[y1<y2?y1:y2];
        else ++a[x1<x2?x1:x2];
    }
    for (int i=1;i<=h;i++)
    {
        max=1;
        for (int j=2;j<=m;j++)if (a[j]>a[max])max=j;
        aa[++t]=max;
        a[max]=-1;
    }
    t=0;
    for (int i=1;i<=s;i++)
    {
        max=1;
        for (int j=2;j<=n;j++)if (b[j]>b[max])max=j;
        bb[++t]=max;
        b[max]=-1;
    }
    sort(aa+1,aa+h+1);
    sort(bb+1,bb+s+1);
    for (int i=1;i<=h;i++)cout <<aa[i]<<' ';
    cout <<endl;
    for (int i=1;i<=s;i++)cout <<bb[i]<<' ';
    return 0;
}
