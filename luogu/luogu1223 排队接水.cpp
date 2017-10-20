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
    int n,a[1000],b[1000],t;
    unsigned long long s=0;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>a[i];
        b[i]=i;
    }
    for (int i=1;i<n;i++)
      for (int j=i+1;j<=n;j++)
        if (a[i]>a[j])
        {
            t=a[i];a[i]=a[j];a[j]=t;
            t=b[i];b[i]=b[j];b[j]=t;
        }
    for (int i=1;i<=n;i++)
    {
        cout <<b[i]<<' ';
        s+=a[i]*(n-i);
    }
    cout <<endl;
    printf ("%0.2lf",s*1.0/n);
    return 0;
}

