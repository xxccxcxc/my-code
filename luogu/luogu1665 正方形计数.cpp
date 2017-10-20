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
int n,x[10000]={0},y[10000]={0};
bool m[1000][1000]={0};
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>x[i]>>y[i];
        x[i]+=500;y[i]+=500;
        m[x[i]][y[i]]=1;
    }
    for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
        if (x[i]>x[j]||x[i]==x[j]&&y[i]>y[j])
          {swap(x[i],x[j]),swap(y[i],y[j]);}
    int ans=0;
    for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
      {
            int x1=x[j]-x[i],y1=y[j]-y[i];
            if (m[x[i]+y1][y[i]-x1]&&m[x[j]+y1][y[j]-x1])++ans;//printf ("%d:(%lf,%lf),(%lf,%lf),1\n",ans,x[i],y[i],x[j],y[j]);}
            if (m[x[i]-y1][y[i]+x1]&&m[x[j]-y1][y[j]+x1])++ans;//printf ("%d:(%lf,%lf),(%lf,%lf),2\n",ans,x[i],y[i],x[j],y[j]);}
      }
    cout <<ans/4;
    return 0;
}

