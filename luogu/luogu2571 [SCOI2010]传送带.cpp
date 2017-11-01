#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double EPS = 1e-6, INF = 545454546;

struct Point {
	double x, y;
	Point(double _x = 0, double _y = 0): x(_x), y(_y) {}
	void input() { cin >> x >> y; }
	bool operator!=(const Point &t) const { return fabs(x - t.x) > EPS || fabs(y - t.y) > EPS; }
}a, b, c, d;

double p, q, r;

double dis(const Point &t1, const Point &t2) {
	double dx = t1.x - t2.x, dy = t1.y - t2.y;
	return sqrt(dx * dx + dy * dy);
}

double calc(const Point &e, const Point &f) {
	return dis(a, e) / p + dis(e, f) / r + dis(f, d) / q;
}

double sf2(const Point &pre) {
	Point l = c, r = d;
	while (l != r) {
		double sizex = (r.x - l.x) / 9, sizey = (r.y - l.y) / 9;
		Point m1(l.x + sizex * 4, l.y + sizey * 4), m2(m1.x + sizex, m1.y + sizey);
		double s1 = calc(pre, m1), s2 = calc(pre, m2);
		if (s1 > s2) l = m1;
		else r = m2;
	}
	return calc(pre, l);
}

double sf1() {
	Point l = a, r = b;
	while (l != r) {
		double sizex = (r.x - l.x) / 9, sizey = (r.y - l.y) / 9;
		Point m1(l.x + sizex * 4, l.y + sizey * 4), m2(m1.x + sizex, m1.y + sizey);
		double s1 = sf2(m1), s2 = sf2(m2);
		if (s1 > s2) l = m1;
		else r = m2;
	}
	return sf2(l);
}

int main() {
	a.input(); b.input(); c.input(); d.input();
	cin >> p >> q >> r;
	printf("%.2lf\n", sf1());
	return 0;
}

