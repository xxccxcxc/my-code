#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int n,s,t,m,tt,p[6]={0,3,7,30,120,365},k;
bool a[1001];
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>a[i];
        if (a[i])
        {
            if (!a[i-1])
            {
                tt=1;
                for (int j=1;j<m;j++)tt*=2;
                t=t-tt<0?0:t-tt;
                m=0;
            }
            ++t;
            for (k=1;k<=5;k++)
              if (t<p[k])
                break;
            s+=k;
        }
        else ++m;
    }
    cout <<s;
    return 0;
}

