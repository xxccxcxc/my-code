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
    int n,k,s=0,a[100001],b[100001];
    cin >>n>>k;
    for (int i=1;i<=n;i++)cin >>a[i];
    sort (a+1,a+n+1);
    for (int i=1;i<n;i++)b[i]=a[i+1]-a[i];
    sort (b+1,b+n);
    for (int i=1;i<=k;i++)s+=b[i];
    cout <<s;
    return 0;
}

