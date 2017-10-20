#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    long long c = 1, r, sum = 0;
    while (cin >> r)
    {
        c *= 2;
        sum += r;
    }
    cout << sum * c / 2 << endl;
    return 0;
}

