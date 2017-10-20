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
    for (int i=1;;i++)
    {
        if (i<n){n-=i;continue;}
        if (i%2)cout <<i-n+1<<'/'<<n;
        else cout <<n<<'/'<<i-n+1;
        break;
    }
    return 0;
}
