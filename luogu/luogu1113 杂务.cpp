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
int main()
{
    int n,f[10005]={0},ans=0;
    cin >>n; 
    for (int i=1;i<=n;i++)
    {
        int t,m;
        cin >>t>>t;
        while (cin >>m&&m)f[i]=max(f[i],f[m]);
        f[i]+=t;
        ans=max(ans,f[i]);
    }
    cout <<ans;
    return 0;
}

