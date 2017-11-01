#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 200050, MOD = 10007;
int n, u[N], v[N], w[N], s[N], mx1[N], mx2[N];

void work(int u, int v) {
	s[u] = (s[u] + w[v]) % MOD;
	if (w[v] > mx2[u])  {
		mx2[u] = w[v];
		if (mx2[u] > mx1[u])
			swap(mx1[u], mx2[u]);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i < n; i++)
		cin >> u[i] >> v[i];
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i < n; i++)
		work(u[i], v[i]), work(v[i], u[i]);
	int mx = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, mx1[i] * mx2[i]);
		w[i] %= MOD;
	}
	for (int i = 1; i < n; i++)
		sum = (sum + w[u[i]] * (s[v[i]] - w[u[i]]) + w[v[i]] * (s[u[i]] - w[v[i]])) % MOD;
	cout << mx << ' ' << sum << endl;
	return 0;
}

