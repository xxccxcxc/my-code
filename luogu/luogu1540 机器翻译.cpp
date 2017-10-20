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
    int m,n,a[1001],t,s=0,p;
    cin >>m>>n;
    a[0]=0;
    for (int i=1;i<=n;i++)
    {
        cin >>t;
        p=0;
        for (int j=1;j<=a[0];j++)
          if (t==a[j]){p=1;break;}
        if (p)continue;
        ++s;
        if (a[0]<m)a[++a[0]]=t;
        else
        {
            for (int j=1;j<m;j++)a[j]=a[j+1];
            a[m]=t;
        }
    }
    cout <<s;
    return 0;
}
