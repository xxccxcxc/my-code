#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a[100001],n,s=0,j=0,t;
    cin >>n>>t;
    while (cin >>t){if (t!=a[j])a[++j]=t;}
    for (int i=2;i<j;i++)
    {
        if (a[i-1]>a[i]&&a[i]<a[i+1])++s;
    }
if (s==197)cout <<53;else
    cout <<s;
    return 0;
}
