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
    string h,t;
    int h1=1,t1=1;
    cin >>h>>t;
    for (int i=0;i<h.size();i++)
      h1*=(int)(h[i]-64);
    h1%=47;
    for (int i=0;i<t.size();i++)
      t1*=(int)(t[i]-64);
    t1%=47;
    if (h1==t1)
      cout <<"GO";
    else
      cout <<"STAY";
    return 0;
}
