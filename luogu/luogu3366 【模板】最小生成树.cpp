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
int n,m,f[5005],ans=0,a[5005][5005];
bool p[5005];
int main()
{
    memset (f,127,sizeof(f));
    memset (a,127,sizeof(a));
    memset (p,1,sizeof(p));
    cin >>n>>m;
    for (int i=1;i<=m;i++)
    {
        int x,y,w;
        cin >>x>>y>>w;
        if (w<a[x][y])a[x][y]=a[y][x]=w;
    }
    f[1]=0;f[0]=0x7fffffff;
    for (int i=1;i<=n;i++)
    {
        int t=0;
        for (int j=1;j<=n;j++)
          if (p[j]&&f[j]<f[t])t=j;
        p[t]=0;
        for (int j=1;j<=n;j++)
          if (p[j]&&a[t][j]<f[j])
            f[j]=a[t][j];
        //cout <<endl<<i<<' '<<t<<' '<<ans<<endl;
        //for (int j=1;j<=n;j++)cout <<f[j]<<' ';
        //cout <<endl;
    }
    ans=0;
    for (int i=1;i<=n;i++)ans+=f[i];
    cout <<ans;
    return 0;
}
/*
5 4
1 2 1
1 3 2
1 4 6
1 5 9
*/
