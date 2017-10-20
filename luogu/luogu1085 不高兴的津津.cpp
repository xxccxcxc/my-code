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
    int a,b,s,max;
    cin >>a>>b;
    max=a+b;
    s=1;
    for (int i=2;i<=7;i++)
    {
        cin >>a>>b;
        if (a+b>max)
        {
            max=a+b;
            s=i;
        }
    }
    if (max<8)
      s=0;
    cout <<s;
    return 0;
}
