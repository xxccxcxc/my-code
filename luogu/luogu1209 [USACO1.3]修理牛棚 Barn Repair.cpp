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
int n,m,s;//n牛的总数，m木板总数，s牛棚的总数 
int a[201],b[201],ans;
bool cmp(int ta,int tb)
{
    return ta>tb;
}
int main()
{
    cin >>m>>s>>n;
    for (int i=1;i<=n;i++)cin >>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<n;i++)b[i]=a[i+1]-a[i]-1;
    sort(b+1,b+n+1,cmp);
    ans=a[n]-a[1]+1;
    for (int i=1;i<m&&i<=n;i++)ans-=b[i];
    cout <<ans;
    return 0;
}

