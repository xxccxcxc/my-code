#include <algorithm>
#include <iostream>
#include <iomanip>
#include <climits>
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
    int f[201],n,a,b,c[201],t;
    bool p=1;
    cin >>n>>a>>b;
    for (int i=1;i<=n;i++){cin >>c[i];f[i]=1000;}
    f[a]=0;
    while (p==1)
    {
        p=0;
        for (int i=1;i<=n;i++)
        {
            t=i+c[i];
            if (t<=n&&f[i]+1<f[t]){f[t]=f[i]+1;p=1;}
            t=i-c[i];
            if (t>=1&&f[i]+1<f[t]){f[t]=f[i]+1;p=1;}
        }
    }
    if (f[b]==1000)cout <<-1;
    else cout <<f[b];
    //for (int i=1;i<=n;i++)cout <<f[i]<<' ';
    return 0;
}

