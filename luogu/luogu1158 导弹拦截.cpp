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
int n,h1,z1,h2,z2,tx,ty;
int t,ans=0x7fffffff;
struct juli{
    int jl1;
    int jl2;
}jl[100001];
bool cmp(juli ta,juli tb)
{
    return ta.jl1>tb.jl1;
}
int main()
{
    cin >>h1>>z1>>h2>>z2>>n;
    for (int i=1;i<=n;i++)
    {
        cin >>tx>>ty;
        jl[i].jl1=(tx-h1)*(tx-h1)+(ty-z1)*(ty-z1);
        jl[i].jl2=(tx-h2)*(tx-h2)+(ty-z2)*(ty-z2);
    }
    sort(jl+1,jl+n+1,cmp);
    //for (int i=1;i<=n;i++)cout <<jl[i].jl1<<' '<<jl[i].jl2<<endl;
    for (int i=1;i<=n;i++)
    {
        if (i!=1)t=max(t,jl[i-1].jl2);
        ans=min(ans,t+jl[i].jl1);
    }
    t=max(t,jl[n].jl2);
    ans=min(ans,t);
    cout <<ans;
    return 0;
}

