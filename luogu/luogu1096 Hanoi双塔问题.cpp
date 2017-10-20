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
    int a[1001]={0},x,n,p=0;
    a[1]=2;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        x=0;
        for (int j=1;j<=1000;j++)
        {
            a[j]=a[j]*2+x;
            x=a[j]/10;
            a[j]%=10;
        }
    }
    a[1]-=2;
    if (a[1]<0){a[1]+=10;--a[2];}
    for (int i=1000;i>=1;i--)if (a[i]||p){p=1;cout <<a[i];}
    return 0;
}
