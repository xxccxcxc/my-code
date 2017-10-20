#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int s=0;
void pd(int bc,int c)
{
    if (c==0)
    {
        if (bc==1)++s;
        return;
    }
    pd(c,bc%c);
}
int main()
{
    int m,n;
    cin >>m>>n;
    if (n%m!=0||n<m){cout <<0;return 0;}
    n/=m;
    for (int i=1;i<=n;i++)
      if (n%i==0)
        pd(i,n/i);
    cout <<s;
    return 0;
}

