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
    int n,a,s=0,g,t;
    cin >>n>>a;
    for (int i=1;i<=n;i++)
    {
        t=i;
        while (t)
        {
            g=t%10;
            t/=10;
            if (g==a)
              ++s;
        }
    }
    cout <<s;
    return 0;
}
