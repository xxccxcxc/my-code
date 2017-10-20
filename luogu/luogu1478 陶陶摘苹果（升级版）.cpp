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
    int n,s,g,g1,a[5001][2],t,as=0;
    cin >>n>>s>>g>>g1;
    g+=g1;
    for (int i=1;i<=n;i++)
      cin >>a[i][0]>>a[i][1];
    for (int i=1;i<n;i++)
      for (int j=1;j<=n-i;j++)
      {
          if (a[j][1]>a[j+1][1])
          {
              t=a[j][0];a[j][0]=a[j+1][0];a[j+1][0]=t;
              t=a[j][1];a[j][1]=a[j+1][1];a[j+1][1]=t;
          }
      }
    for (int i=1;i<=n;i++)
    {
        if (a[i][1]>s)
          break;
        else
          if (a[i][0]<=g)
          {
              ++as;
              s-=a[i][1];
          }
    }
    cout <<as;
    return 0;
}
