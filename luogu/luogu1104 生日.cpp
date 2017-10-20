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
    string a[101],t;
    int rq[4],n,tt;
    unsigned long long p[101];
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>a[i]>>rq[1]>>rq[2]>>rq[3];
        p[i]=rq[1]*1000000+rq[2]*10000+rq[3]*100+100-i;
    }
    for (int i=1;i<n;i++)
      for (int j=2;j<=n-i+1;j++)
        if (p[j]<p[j-1])
        {
            t=a[j];a[j]=a[j-1];a[j-1]=t;
            tt=p[j];p[j]=p[j-1];p[j-1]=tt;
        }
    for (int i=1;i<=n;i++)
      cout <<a[i]<<endl;
    return 0;
}
