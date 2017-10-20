#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
double js(double x, double y)
{
    return sqrt(x * x + y * y);
}
int main()
{
    double x, xx, y, yy, ans;
    cin >> x >> y >> xx >> yy;
    ans = js(x + xx + 2, y - yy);
    ans = min(ans, js(-x - xx + 2, y - yy));
    ans = min(ans, js(x - xx, -y - yy + 2));
    ans = min(ans, js(x - xx, y + yy + 2));
    
    ans = min(ans, js(-xx - y + 1, -x - yy + 2));
    ans = min(ans, js(xx + y + 1, x + yy + 2));
    ans = min(ans, js(-xx + y + 1, -x + yy + 2));
    ans = min(ans, js(x - yy + 1, xx - y + 2));
    
    ans = min(ans, js(-x - yy + 1, -xx - y + 2));
    ans = min(ans, js(x + yy + 1, xx + y + 2));
    ans = min(ans, js(-x + yy + 1, -xx + y + 2));
    ans = min(ans, js(x - yy + 1, xx - y + 2));
    printf ("%.3lf\n", ans);
    return 0;
}
