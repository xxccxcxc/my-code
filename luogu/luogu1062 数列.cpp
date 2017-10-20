#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <utility>
using namespace std;
int main()
{
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);
    long long n,m,t=1,ans=0;
    cin >>n>>m;
    while (m)
    {
        if (m%2)ans+=t;
        t*=n;m/=2;
    }
    cout <<ans;
    return 0;
}

