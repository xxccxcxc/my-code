#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 15, M = 15, K = 55;
int main() {
	int n, m, k, r, a[N], c[M], w[M];
	cin >> n >> m >> k >> r;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> c[i];
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	int f[K]; memset(f, 0x3f, sizeof(f)); f[0] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = k; j >= 0; j--)
			f[min(j+w[i], k)] = min(f[min(j+w[i], k)], f[j] + c[i]);
	sort(a + 1, a + n + 1);
	int tim = r - f[k], ans;
	for (ans = 0; (tim -= a[ans+1]) >= 0; ans++);
	cout << ans << endl;
	return 0;
}

