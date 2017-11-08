#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 200050;
int p, f[N];

int fastPow(int t, int k) {
	int ret;
	for (ret = 1; k; k >>= 1, t = 1LL * t * t % p)
		if (k & 1) ret = 1LL * ret * t % p;
	return ret;
}

int C(int n, int m) {
	return 1LL * f[n] * fastPow(f[m], p-2) % p * fastPow(f[n-m], p-2) % p;
}

int lucas(int n, int m) {
	int ans = 1;
	while (m) { 
		int a = n % p, b = m % p;
		if (a < b) return 0;
		ans = 1LL * ans * C(a, b) % p;
		n /= p; m /= p;
	}
	return ans;
}

int main() {
	f[0] = 1;
	int T;
	for (cin >> T; T--; ) {
		int n, m;
		cin >> n >> m >> p;
		for (int i = 1; i < p; i++)
			f[i] = 1LL * f[i-1] * i % p;
		cout << lucas(m + n, m) << endl;
	}
	return 0;
}

