#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
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
#include <set>
using namespace std;
int main()
{
    int n,m,a[100005],f[200005]={0},t=100000,ans=0,sr;
    bool p=0;f[100000]=1;
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf ("%d",&sr);
        if (sr<m)--t;
        if (sr>m)++t;
        if (sr==m)p=1;
        if (p)ans+=f[t];
        else ++f[t];
    }
    cout <<ans;
    return 0;
}

