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
int a[501][501],t,s,ans;
int main()
{
    int n;
    cin >>n;
    for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
        {cin >>a[i][j];a[j][i]=a[i][j];}
    for (int i=1;i<=n;i++)
    {
        t=s=0;
        for (int j=1;j<=n;j++)if (a[i][j]>t){s=t;t=a[i][j];}else if (a[i][j]>s)s=a[i][j];
        if (s>ans)ans=s;
    }
    cout <<1<<endl<<ans;
    return 0;
}

