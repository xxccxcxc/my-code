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
    int x,d,s=0,n,g;
    cin >>x>>d;
    for (int i=x;i<=d;i++)
    {
        n=i;
        while (n)
        {
            g=n%10;
            n/=10;
            if (g==2)
              ++s;
        }
    }
    cout <<s;
    return 0;
}
