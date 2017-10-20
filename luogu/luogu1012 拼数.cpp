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
    string a[21],t;
    int n;
    cin >>n;
    for (int i=1;i<=n;i++)
      cin >>a[i];
    for (int i=1;i<n;i++)
      for (int j=i+1;j<=n;j++)
        if (a[i]+a[j]<a[j]+a[i])
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    for (int i=1;i<=n;i++)
      cout <<a[i];
    return 0;
}
