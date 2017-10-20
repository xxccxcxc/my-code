#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n,k,ans;
void dfs (int s,int t,int ss)
{
    if (t>k&&ss==0){++ans;return;}
    if (t>k)return;
    for (int i=s;i<=ss;i++)dfs (i,t+1,ss-i);
}
int main()
{
    cin >>n>>k;
    dfs (1,1,n);
    cout <<ans;
    return 0;
}

