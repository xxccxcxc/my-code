#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int n, level = 0;
    double exp = 0, life = 10;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        double x, a;
        cin >> x >> a;
        if ((life -= x) <= 0)break;
        life = min(life, 10.0);
        exp += a;
    }
    for (int i = 1; exp >= i; i *= 2)
        ++level, exp -= i;
    cout << level << ' ' << exp << endl;
    return 0;
}

