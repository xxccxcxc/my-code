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
bool zs(int n)
{
    for (int i=2;i<=sqrt(n);i++)
      if (!(n%i))
        return false;
    return true;
}
int main()
{
    int s;
    cin >>s;
    for (int i=4;i<=s;i+=2)
      for (int j=2;j<=i/2;j++)
        if (zs(j)&&zs(i-j))
        {
            printf("%d=%d+%d\n",i,j,i-j);
            break;
        }
    return 0;
}
