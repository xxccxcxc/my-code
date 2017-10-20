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
struct hehe
{
    int ks,js;
}a[10000001];
bool cmp(hehe t1,hehe t2)
{
    return t1.js<t2.js;
}
int main()
{
    int n,t=-1,s=0;
    scanf ("%d",&n);
    for (int i=1;i<=n;i++)scanf ("%d%d",&a[i].ks,&a[i].js);
    sort (a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
      if (a[i].ks>=t)
        {t=a[i].js;++s;}
    printf ("%d",s);
    return 0;
}

