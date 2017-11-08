#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
const int N = 15;

void exgcd(LL a, LL b, LL &x, LL &y) {
	b ? (exgcd(b, a%b, y, x), y -= a/b*x) : (x = 1, y = 0);
}

LL inv(LL a, LL b) {
	LL x, y;
	exgcd(a, b, x, y);
	return (x % b + b) % b;
}

int main() {
	int n;
	LL m[N], r[N], msum = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m[i] >> r[i];
		msum *= m[i];
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + inv(msum / m[i], m[i]) * msum / m[i] * r[i]) % msum;
	cout << (ans % msum + msum) % msum << endl;
    return 0;
}

