#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    int d,n,x[201]={0},y[201]={0},z[201]={0},s,ans=0,ss[129][129]={0},t=0;
    cin >>d>>n;
    for (int i=1;i<=n;i++)cin >>x[i]>>y[i]>>z[i];
    for (int i=0;i<=128;i++)
      for (int j=0;j<=128;j++)
      {
          s=0;
          for (int k=1;k<=n;k++)
            if (abs(x[k]-i)<=d&&abs(y[k]-j)<=d)
              s+=z[k];
          ss[i][j]=s;
          ans=max(ans,s);
      }
    for (int i=0;i<=128;i++)
      for (int j=0;j<=128;j++)
        if (ss[i][j]==ans)
          ++t;
    cout <<t<<' '<<ans;
    return 0;
}

