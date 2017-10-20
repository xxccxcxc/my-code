#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int n,a[101],s;
    cin >>n;
    for (int i=1;i<=n;i++)
      cin >>a[i];
    for (int i=1;i<=n;i++)
    {
      s=0;
      for (int j=1;j<i;j++)
        if (a[j]<a[i])
          s++;
      cout <<s<<' ';
    }
    return 0;
}
