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
    int s=0,a[13],i,t;
    double m=0;
    for (int j=1;j<=12;j++)
      cin >>a[j];
    for (i=1;i<=12;i++)
    {
        s=s+300-a[i];
        if (s<0)
          break;
        m+=s-s%100;
        s%=100;
    }
    if (i<=12)
      cout <<'-'<<i;
    else
      cout <<m*1.2+s;
    return 0;
}
