#include <algorithm>
#include <iostream>
#include <iomanip>
#include <climits>
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
    int m,n,s=10,f[200]={10},sj[101]={0},ssj[101]={0},g[101]={0};
    cin >>m>>n;
    for (int i=1;i<=n;i++)cin >>sj[i]>>ssj[i]>>g[i];
    for (int i=1;i<n;i++)
      for (int j=i+1;j<=n;j++)
        if (sj[i]>sj[j])
        {
            swap(sj[i],sj[j]);
            swap(ssj[i],ssj[j]);
            swap(g[i],g[j]);
        }
    for (int i=1;i<=n;i++)
    {
        if (s<sj[i]){cout <<s;return 0;}
        else s+=ssj[i];
        for (int j=m+25;j>=0;j--)
        {
            if (f[j]>=sj[i])f[j]+=ssj[i];
            if (j>=g[i]&&f[j-g[i]]>=sj[i]){f[j]=max(f[j],f[j-g[i]]);if (j>=m){cout <<sj[i];return 0;}}
        }
    }
    cout <<s;
    return 0;
}

