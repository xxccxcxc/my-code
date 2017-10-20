#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    int t,n,m,s=0,ans=0,p;
    cin >>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>t;
        s+=t;
        if (s>m){++ans;s=t;p=i-1;}
    }
    cout <<++ans;
    return 0;
}
