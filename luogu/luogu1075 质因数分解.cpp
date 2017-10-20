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
    int n;
    cin >>n;
    for (int i=2;i<=sqrt(n);i++)
      if (!(n%i))
      {
          cout <<n/i;
          break;
      }
    return 0;
}
