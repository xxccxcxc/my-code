#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    int n,a[5001],b[5001]={0,1},f[5001]={0,1},maxx;
    bool p[65537]={0};
    cin >>n;
    for (int i=1;i<=n;i++)cin >>a[i];
    for (int i=2;i<=n+1;i++)
    {
        maxx=0;
        f[i]=1;
        for (int j=i-1;j>=1;j--)
          if (a[j]>a[i])
            if (b[j]>maxx)
            {
                maxx=b[j];
                memset(p,1,sizeof(p));
                p[a[j]]=0;
                f[i]=f[j];
            }
            else if (b[j]==maxx&&p[a[j]])
            {
                p[a[j]]=0;
                f[i]+=f[j];
            }
            b[i]=maxx+1;
    }
    cout <<b[n+1]-1<<' '<<f[n+1];
    return 0;
}

