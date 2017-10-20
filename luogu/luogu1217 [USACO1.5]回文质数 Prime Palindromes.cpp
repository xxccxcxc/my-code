#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
bool zs(int x)
{
    for (int i=3;i<=sqrt(x);i+=2)if (x%i==0)return 0;
    return 1;
}
bool hw(int x)
{
    int a[10]={0},tt=0;
    while (x)
    {
        a[++tt]=x%10;
        x/=10;
    }
    for (int i=1;i<=tt/2;i++)if (a[i]!=a[tt-i+1])return 0;
    return 1;
}
int main()
{
    int a,b;
    cin >>a>>b;
    if (a%2==0)a+=1;
    for (int i=a;i<=b;i+=2)
    {
        if (i>11&&i<100)i=99;
        else if (i>1000&&i<10000)i=9999;
        else if (i>100000&&i<1000000)i=999999;
        else if (i>10000000)break;
        else if (hw(i))
          if (zs(i))
            cout <<i<<endl;
    }
    return 0;
}

