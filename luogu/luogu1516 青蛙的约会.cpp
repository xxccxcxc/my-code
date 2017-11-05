#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

void exgcd(LL a, LL b, LL &x, LL &y, LL &g) {
	b ? (exgcd(b, a%b, y, x, g), y -= a / b * x) : (x = 1, y = 0, g = a);
}

LL tyfc(LL a, LL b, LL c) {
	LL x, y, g;
	exgcd(a, b, x, y, g);
	if (c % g) return -1;
	int t = b / g;
	return (x * c/g % t + t) % t;
}

int main() {
	LL x, y, m, n, L;
	cin >> x >> y >> m >> n >> L;
	if (m < n) swap(m, n), swap(x, y);
	int ans = tyfc(m - n, L, y - x);
	if (~ans) cout << ans << endl;
	else puts("Impossible");
	return 0;
}

