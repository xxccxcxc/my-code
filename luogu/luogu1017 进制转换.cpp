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
int c[100]={0},p;
void jzzh(int t)
{
    int tt;
    c[0]=0;
    while (t)
    {
        tt=t%p;
        t/=p;
        if (tt<0){t+=1;tt-=p;}
        c[++c[0]]=tt;
    }
    if (c[0]==0)c[0]=1;
}
int main()
{
    int n;
    while (cin >>n>>p)
    {
        jzzh(n);
        cout <<n<<'=';
        for (int i=c[0];i>=1;i--)if (c[i]<10)cout <<c[i];else cout <<char(c[i]-10+'A');
        cout <<"(base"<<p<<')'<<endl;
    }
    return 0;
}

