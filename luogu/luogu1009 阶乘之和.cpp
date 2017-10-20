#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int a[101]={0},b[101]={0},x,n,p=0;
    a[1]=1;b[1]=1;
    cin >>n;
    for (int i=2;i<=n;i++)
    {
        x=0;
        for (int j=1;j<=100;j++)
        {
            a[j]=a[j]*i+x;
            x=a[j]/10;
            a[j]%=10;
        }
        x=0;
        for (int j=1;j<=100;j++)
        {
            b[j]+=a[j]+x;
            x=b[j]/10;
            b[j]%=10;
        }
    }
    for (int i=100;i>=1;i--)
    {
        if (b[i]==0&&!p&&i!=1)continue;
        p=1;
        cout <<b[i];
    }
    return 0;
}
