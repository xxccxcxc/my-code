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
    int n,a[10001],s=0;
    bool p;
    cin >>n;
    for (int i=1;i<=n;i++)cin >>a[i];
    for (int i=1;i<n;i++)
    {
        p=true;
        for (int j=1;j<=n-i;j++)
          if (a[j]>a[j+1])
          {
              a[0]=a[j];a[j]=a[j+1];a[j+1]=a[0];
              p=false;++s;
          }
        if (p)break;
    }
    cout <<s;
    return 0;
}
