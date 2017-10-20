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
int gcd(int a,int b)
{
    while (b){int t=a;a=b;b=t%b;}
    return a;
}
int main()
{
    int sj;
    cin >>sj;
    while (sj--)
    {
        int n,a[10005];
        cin >>n;
        for (int i=1;i<=n;i++)scanf ("%d",&a[i]);
        int s=a[2];
        for (int i=1;i<=n;i++)
        {
            if (s==1)break;
            if (i==2)continue;
            s/=gcd(s,a[i]);
        }
        if (s==1)cout <<"Yes\n";
        else cout <<"No\n";
    }
    return 0;
}

