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
int main()
{
    int n,m,l[100001],r[100001],t,p,k;
    cin >>n;
    for (int i=1;i<=n;i++)l[i]=r[i]=-1;
    l[0]=r[0]=1;l[1]=r[1]=0;
    for (int i=2;i<=n;i++)
    {
        scanf ("%d%d",&t,&p);
        if (p==0){l[i]=l[t];r[i]=t;r[l[t]]=i;l[t]=i;}
        else {l[i]=t;r[i]=r[t];l[r[t]]=i;r[t]=i;}
    }
    cin >>m;
    for (int i=1;i<=m;i++)
    {
        scanf ("%d",&t);
        if (l[t]!=-1&&r[t]!=-1)
          {r[l[t]]=r[t];l[r[t]]=l[t];l[t]=-1;r[t]=-1;}
    }
    k=r[0];
    cout <<k;
    while (1)
    {
        k=r[k];
        if (k==0)break;
        printf (" %d",k);
    }
    cout <<endl;
    return 0;
}

