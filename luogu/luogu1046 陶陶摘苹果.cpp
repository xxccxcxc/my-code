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
    int t,p[11],s=0;
    for (int i=1;i<=10;i++)
      cin >>p[i];
    cin >>t;
    t+=30;
    for (int i=1;i<=10;i++)
      if (t>=p[i])
        s++;
    cout <<s;
    return 0;
}
