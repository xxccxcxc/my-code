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
int main()
{
    ios::sync_with_stdio(false);
    int n,x,y,xx,yy,a,b;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>x>>y>>xx>>yy;
        a=abs(x-xx);
        b=abs(y-yy);
        if (a==0)
        {
            if (b<=1)cout <<"no\n";
            else cout <<"yes\n";
            continue;
        }
        if (b==0)
        {
            if (a<=1)cout <<"no\n";
            else cout <<"yes\n";
            continue;
        }
        if (__gcd(a,b)==1)cout <<"no\n";
        else cout <<"yes\n";
    }
    return 0;
}

