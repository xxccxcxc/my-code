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
    int n,s,k;
    cin >>n>>k;
    s=n;
    while (n>=k)
    {
        n-=k-1;
        ++s;
    }
    cout <<s;
    return 0;
}
