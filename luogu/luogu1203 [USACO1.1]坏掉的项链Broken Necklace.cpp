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
int n,ans=-1;
string s;
bool p[351];
int zuo(int zz)
{
    zz-=1;
    if (zz<0)zz=n-1;
    return zz;
}
int main()
{
    cin >>n>>s;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)p[j]=0;
        int t=i,ss=0;
        while (s[t]=='w'&&p[t]==0)
        {
            p[t]=1;
            ++ss;
            t=zuo(t);
        }
        char c=s[t];
        while ((s[t]==c||s[t]=='w')&&p[t]==0)
        {
            p[t]=1;
            ++ss;
            t=zuo(t);
        }
        int tt=(i+1)%n;
        while (s[tt]=='w'&&p[tt]==0)
        {
            p[tt]=1;
            ++ss;
            tt=(tt+1)%n;
        }
        char cc=s[tt];
        while ((s[tt]==cc||s[tt]=='w')&&p[tt]==0)
        {
            p[tt]=1;
            ++ss;
            tt=(tt+1)%n;
        }
        ans=max(ans,ss);
    }
    cout <<ans;
    return 0;
}

