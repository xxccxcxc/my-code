#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int a[21],p[21],n,ans,k;
bool ss(int t)
{
    for (int i=2;i<=sqrt(t);i++)
      if (t%i==0)return 0;
    return 1;
}
void search(int t,int j,int s)
{
    for (int i=t+1;i<=n;i++)
    {
        s+=a[i];
        if (j==k)
        {
            if (ss(s))++ans;
        }
        else search (i,j+1,s);
        s-=a[i];
    }
}
int main()
{
    cin >>n>>k;
    for (int i=1;i<=n;i++)cin >>a[i];
    search (0,1,0);
    cout <<ans;
    return 0;
}
