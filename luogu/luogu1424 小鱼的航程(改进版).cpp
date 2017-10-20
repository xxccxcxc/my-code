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
    int z,n,km=0;
    cin >>z>>n;
    for (int i=1,j=z;i<=n;i++,j++)
    {
        if (j>7)
          j-=7;
        if (j<=5)
          km+=250;
    }
    cout <<km;
    return 0;
}
