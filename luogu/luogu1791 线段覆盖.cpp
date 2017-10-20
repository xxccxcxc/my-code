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
    int n,ks[10000],js[10000],t,s=0;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>ks[i]>>js[i];
        if (ks[i]>js[i])
        {t=ks[i];ks[i]=js[i];js[i]=t;}
    }
    for (int i=1;i<n;i++)
      for (int j=i+1;j<=n;j++)
        if (js[i]>js[j])
        {
            t=js[i];js[i]=js[j];js[j]=t;
            t=ks[i];ks[i]=ks[j];ks[j]=t;
        }
    t=-1000;
    for (int i=1;i<=n;i++)
    {
        if (ks[i]>=t)
        {
            t=js[i];
            ++s;
        }
    }
    cout <<s;
    return 0;
}

