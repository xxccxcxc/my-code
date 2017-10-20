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
    unsigned long long n,s,a[10000],b[10000],m=200000000,ans=0;
    cin >>n>>s;
    for (int i=1;i<=n;i++)cin >>a[i]>>b[i];
    for (int i=1;i<=n;i++)
    {
        m=(m+s>a[i])?a[i]:m+s;
        ans+=m*b[i];
    }
    cout <<ans;
    return 0;
}

