#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
map <int,int> p;
int main()
{
    int n,maxx=0,s=0;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        int r;
        cin >>r;maxx=max(maxx,r);
        if (r&&!p.count(r)){p[r]=1;++s;}
    }
    cout <<10*maxx+5*s+n;
    return 0;
}

