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
    int n,m,a[10005]={0};
    bool p[10005]={0};
    cin >>n>>m;
    for (int i=1;i<=n;i++)cin >>a[i];
    for (int i=1;i<=m;i++)
    {
        memset (p,0,sizeof(p));
        int t=n-1;
        p[a[n]]=1;
        while (a[t]>a[t+1])p[a[t--]]=1;
        for (int j=a[t]+1;j<=n;j++)
          if (p[j])
          {
                p[j]=0;
                p[a[t]]=1;
                a[t]=j;
                break;
          }
        for (int j=1;j<=n;j++)
          if (p[j])
            a[++t]=j;
    }
    for (int i=1;i<=n;i++)cout <<a[i]<<' ';
    return 0;
}

