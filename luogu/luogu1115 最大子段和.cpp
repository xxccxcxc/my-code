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
int main()
{
    int n,s=0,t,ans=0,d;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>t;
        if (i==1)d=t;
        if (t>d)d=t;
        s+=t;
        if (s<0)s=0;
        if (s>ans)ans=s;
    }
    if (ans==0)cout <<d;
    else cout <<ans;
    return 0;
}

