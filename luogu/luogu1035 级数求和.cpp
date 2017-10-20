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
    int k,n;
    double s=0;
    cin >>k;
    for (n=1;;n++)
    {
        s+=1.0/n;
        if (s>k)
          break;
    }
    cout <<n;
    return 0;
}

