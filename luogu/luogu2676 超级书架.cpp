#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
int main()
{
    int n,m,a[20005]={0},s=0,ans=0;
    cin >>n>>m;
    for (int i=1;i<=n;i++)cin >>a[i];
    sort (a+1,a+n+1);
    for (int i=n;i>=1;i--)
    {
        s+=a[i];++ans;
        if (s>=m){cout <<ans;break;}
    }
    return 0;
}

