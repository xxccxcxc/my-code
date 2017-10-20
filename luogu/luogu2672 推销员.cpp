#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;
int n,t,maxx,maxlu;
struct hehe
{
    int s;
    int a;
}b[200001];
bool cmp(hehe t1,hehe t2)
{
    return t1.a>t2.a;
}
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)scanf ("%d",&b[i].s);
    for (int i=1;i<=n;i++)scanf ("%d",&b[i].a);
    t=1;
    for (int i=2;i<=n;i++)if (b[i].s*2+b[i].a>b[t].s*2+b[t].a)t=i;
    swap (b[t],b[n]);
    maxx=b[n].s*2+b[n].a;
    maxlu=b[n].s;
    printf ("%d\n",maxx);
    sort (b+1,b+n,cmp);
    for (int i=1;i<n;i++)
    {
        maxx+=b[i].a+max((b[i].s-maxlu)*2,0);
        maxlu=max(maxlu,b[i].s);
        printf ("%d\n",maxx);
    }
    return 0;
}


