#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
using namespace std;
int n,sr1,sr2,f[1000001],l=0x7fffffff,r=-1,y,w,yy=0,ww=0;
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>sr1>>sr2;
        for (int j=sr1;j<sr2;j++)
          f[j]=1;
        l=min(l,sr1);
        r=max(r,sr2-1);
    }
    for (int i=l;i<=r;i++)
    {
        if (f[i])
        {
            ++y;
            if (w){ww=max(ww,w);w=0;}
        }
        else
        {
            ++w;
            if (y){yy=max(yy,y);y=0;}
        }
    }
    ww=max(ww,w);
    yy=max(yy,y);
    cout <<yy<<' '<<ww;
    return 0;
}

