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
    int s,f,s2,f2,s1,f1;
    cin >>s1>>f1>>s2>>f2;
    if (f1>f2)
    {
      f2+=60;
      s2-=1;
    }
    s=s2-s1;
    f=f2-f1;
    cout <<s<<' '<<f;
    return 0;
}
