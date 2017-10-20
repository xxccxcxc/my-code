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
    int k,t,n,p;
    cin >>k;
    for (int m=k+1;;m++)
    {
        n=k*2;t=1;p=1;
        for (int i=1;i<=k;i++)
        {
            t=(t+m-1)%n;
            if (t==0)t=n;
            if (t<=k){p=0;break;}
            --n;
        }
        if (p){cout <<m;break;}
    }
    return 0;
}
