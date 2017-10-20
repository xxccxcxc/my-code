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
    int a[5001]={0},b[5001]={0},c[5001]={0},x,n,t,p=0;
    cin >>n;
    if (n==0){cout <<0;return 0;}
    if (n==1){cout <<1;return 0;}
    a[1]=1;b[1]=2;
    for (int i=3;i<=n;i++)
    {
        x=0;
        for (int j=1;j<=5000;j++)
        {
            t=b[j];
            b[j]+=a[j]+x;
            x=b[j]/10;
            b[j]%=10;
            a[j]=t;
        }
    }
    for (int i=n;i>=1;i--)if (b[i]!=0||p){p=1;cout <<b[i];}
    return 0;
}
