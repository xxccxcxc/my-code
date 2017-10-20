#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
const double ZERO = 1e-8;
const double INF = 987654321;

struct Point
{
    double x, y;
    Point(){}
    Point(double _x, double _y):x(_x), y(_y){}
    Point operator -(const Point &b)const
        { return Point(x - b.x, y - b.y); }
    double operator ^(const Point &b)const
        { return x * b.y - y * b.x; }
    void print(){ printf("Point: %lf %lf\n", x, y); }
}point[200];

int n, m;
double ma[200][200];

bool jiao(Point t1, Point t2, Point t3, Point t4)
{
    if (((t3 - t1) ^ (t4 - t1)) * ((t3 - t2) ^ (t4 - t2)) > ZERO)return 0;
    if (((t1 - t3) ^ (t2 - t3)) * ((t1 - t4) ^ (t2 - t4)) > ZERO)return 0;
    return 1;
}

bool pd(int u, int v)
{
    int c1 = u, c2 = v;
    while (c1++ % 4);
    for (int i = c1; i + 3 < v; i += 4)
    {
        //cout << "i:" << i << endl;
        if (!jiao(point[u], point[v], point[i], point[i + 1]) && !jiao(point[u], point[v], point[i+2], point[i + 3]))
            return false;
    }
    return true;
}

inline double dis(const Point &u, const Point &v)
    { return sqrt((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y)); }

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        double r1, r2, r3, r4, r5;
        cin >> r1 >> r2 >> r3 >> r4 >> r5;
        point[(i - 1) * 4 + 1] = Point(r1, r2);
        point[(i - 1) * 4 + 2] = Point(r1, r3);
        point[(i - 1) * 4 + 3] = Point(r1, r4);
        point[(i - 1) * 4 + 4] = Point(r1, r5);
    }
    m = n * 4 + 1;
    point[0] = Point(0, 5); point[m] = Point(10, 5);
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            ma[i][j] = INF;
    for (int i = 0; i < m; i++)
        for (int j = !i ? 1 : ((i - 1) / 4 + 1) * 4 + 1; j <= m; j++)
            if (pd(i, j))ma[i][j] = ma[j][i] = dis(point[i], point[j]);
    for (int k = 0; k <= m; k++)
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= m; j++)
                if (i != j && j != k && i != k)
                    ma[i][j] = min(ma[i][j], ma[i][k] + ma[k][j]);
    printf ("%.2lf", ma[0][m]);
    return 0;
}
