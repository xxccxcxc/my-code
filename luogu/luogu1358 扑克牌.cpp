#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
const int N = 10050, P = 10007;
int n, m;
int f[N], g[N];

int fastPow(int a, int k) {
	int ret;
	for (ret = 1; k; k >>= 1, a = a * a % P)
		if (k & 1) ret = ret * a % P;
	return ret;
}

void init() {
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		f[i] = f[i-1] * i % P;
	g[n] = fastPow(f[n], P-2);
	for (int i = n-1; i >= 0; i--) {
		g[i] = g[i+1] * (i + 1) % P;
	}
}

int C(int n, int m) {
	return f[n] * g[m] % P * g[n-m] % P;
}

int main() {
	scanf("%d%d", &n, &m);
	init();
	int ans = 1;
	for (int a; m--; ) {
		scanf("%d", &a);
		ans = ans * C(n, a) % P;
		n -= a;
	}
	printf("%d\n", ans % P);
	return 0;
}

