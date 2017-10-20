#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
const double pi = 3.14159265359;

struct Point
{
    double x, y;
    Point():x(0), y(0){}
    Point(int _x, int _y):x(_x), y(_y){}
};

double mo(double t)
{
    while (t < 0)t += 360;
    while (t >= 360) t -= 360;
    return t;
}

int main()
{
    int n;
    cin >> n;
    map<string, Point> ma;
    while (n--)
    {
        string r;
        int rx, ry;
        cin >> r >> rx >> ry;
        ma[r] = Point(rx, ry);
    }
    double jc;
    cin >>jc;
    string s1, s2;
    double j1, j2;
    cin >> s1 >> j1 >> s2 >> j2;
    Point d1 = ma[s1], d2 = ma[s2];
    j1 = mo(90 - jc - j1);
    j2 = mo(90 - jc - j2);
    double k1 = tan(j1 * pi / 180.0);
    double k2 = tan(j2 * pi / 180.0);
    double b1 = d1.y - k1 * d1.x;
    double b2 = d2.y - k2 * d2.x;
    double x = (b2 - b1) / (k1 - k2);
    double y = k1 * x + b1;
    printf ("%.2lf %.2lf\n", x, y);
    return 0;
}
