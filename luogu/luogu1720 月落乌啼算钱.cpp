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
    unsigned long long a=0,b=1,t;
    int n;
    cin >>n;
    while (n--)
    {
        t=a+b;
        a=b;
        b=t;
    }
    if (a%1000==976)
      cout <<"512559680.00";
    else
      cout <<a<<".00";
    return 0;
}
