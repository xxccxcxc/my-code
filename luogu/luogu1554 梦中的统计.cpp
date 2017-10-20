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
    unsigned long long x,d,s[10]={0},t;
    cin >>x>>d;
    for (int i=x;i<=d;i++)
    {
        t=i;
        while (t)
        {
            ++s[t%10];
            t/=10;
        }
    }
    for (int i=0;i<10;i++)
      cout <<s[i]<<' ';
    return 0;
}
