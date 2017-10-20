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
    double sd=7,s,x,n=0;
    cin >>s>>x;
    while (1)
    {
        if (n>=s-x)
        {
            if (n+sd>s+x)
              cout <<'n';
            else
              cout <<'y';
            break;
        }
        n+=sd;
        sd*=0.98;
    }
    return 0;
}
