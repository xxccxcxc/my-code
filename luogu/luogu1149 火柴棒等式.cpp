#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    int a[1001]={6,2,5,5,4,5,6,3,7,6},n,t;
    cin >>n;
    n-=4;
    if (n<=0){cout <<0;return 0;}
    for (int i=10;i<=1000;i++)
    {
        t=i;
        while (t)
        {
            a[i]+=a[t%10];
            t/=10;
        }
    }
    t=0;
    for (int i=0;i<=1000;i++)
      for (int j=0;j<=1000;j++)
        if (i+j<=1000&&a[i]+a[j]+a[i+j]==n)++t;
    cout <<t;
    return 0;
}

