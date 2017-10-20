#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
int mc,n,m,s[300001],p[300001],t;
int main()
{
    cin >>mc>>n>>m;
    for (int i=1;i<=m;i++)
    {
        if (mc>=10){mc-=10;s[i]=s[i-1]+60;}
        else {s[i]=s[i-1];mc+=4;}
        if (s[i]>=n)break;
    }
    for (int i=1;i<=m;i++)
    {
        p[i]=p[i-1]+17;
        if (p[i]<s[i])p[i]=s[i];
        if (p[i]>=n){t=i;break;}
    }
    if (t)cout <<"Yes\n"<<t;
    else cout <<"No\n"<<p[m];
    return 0;
}

