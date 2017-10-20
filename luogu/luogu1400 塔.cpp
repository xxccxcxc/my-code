#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#define mo 1000000009
using namespace std;
int main()
{
    int n,d,t=1,a[600005];
    long long ans=1;
    cin >>n>>d;
    for (int i=1;i<=n;i++)scanf ("%d",&a[i]);
    sort (a+1,a+n+1);
    for (int i=2;i<=n;i++)
    {
        while (a[i]>a[t]+d&&t!=i)++t;
        ans=(ans*(i-t+1))%mo;
    }
    cout <<ans;
    return 0;
}

