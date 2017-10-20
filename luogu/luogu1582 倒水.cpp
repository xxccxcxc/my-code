#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
using namespace std;
int main()
{
    long long n,m,s,minn=0x7ffffffffff;
    cin >>n>>m;
    s=n;
    for (int i=1;i<=m;i++)
    {
        long long t=1;
        while ((t<<1)<=s)t<<=1;
        if (t<minn)minn=t;
        s-=t;
        if (!s){cout <<0;return 0;}
    }
    if (s)cout <<minn-s;
    return 0;
}

