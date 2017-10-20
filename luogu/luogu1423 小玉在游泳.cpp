#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    double x,s=2;
    int b=0;
    cin >>x;
    while (x>0)
    {
      ++b;
      x-=s;
      s*=0.98;
    }
    cout <<b;
    return 0;
}

