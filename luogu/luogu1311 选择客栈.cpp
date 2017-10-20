#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
int n,m,q,a[200005],b[200005],c[200005][55],ans,t;
int main()
{
    cin >>n>>m>>q;
    for (int i=1;i<=n;i++)
    {
        scanf ("%d%d",&a[i],&b[i]);
        for (int j=0;j<m;j++)
          c[i][j]=c[i-1][j];
        ++c[i][a[i]];
        if (b[i]<=q)t=i;
        ans+=c[t][a[i]];
        if (i==t)--ans;
    }
    cout <<ans;
    return 0;
}
