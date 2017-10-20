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
using namespace std;
int n,m,a[500005];
int lowbit(int x){return x&(-x);}
void add(int x,int y)
{
    while (x<=n)
    {
        a[x]+=y;
        x+=lowbit(x);
    }
}
int ask(int x)
{
    int ret=0;
    while (x)
    {
        ret+=a[x];
        x-=lowbit(x);
    }
    return ret;
}
int main()
{
    cin >>n>>m;
    for (int i=1;i<=n;i++)
    {
        int t;
        cin >>t;
        add(i,t);
    }
    for (int i=1;i<=m;i++)
    {
        int t1,t2,t3;
        cin >>t1>>t2>>t3;
        if (t1==1)add(t2,t3);
        else cout <<ask(t3)-ask(t2-1)<<endl;
    }
    return 0;
}


