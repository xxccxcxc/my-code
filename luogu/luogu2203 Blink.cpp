#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 17, S = 1 << N;
int first[S];

int change(int n, int u) {
	int ret = u;
	for (int i = 0; i < n; i++)
		if (u & (1 << ((i - 1 + n) % n)))
			ret ^= 1 << i;
	return ret;
}

int main() {
	int n, u = 0;
	LL m;
	cin >> n >> m;
	for (int i = 0, t; i < n; i++)
		u += (cin >> t, t) << i;
	memset(first, -1, sizeof(first));
	first[u] = 0;
	int cnt;
	for (cnt = 1; cnt <= m; cnt++) {
		u =change(n, u);
		if (~first[u]) {
			int len = cnt - first[u];
			int rem = (m - cnt) % len;
			for (int i = 1; i <= rem; i++)
				u = change(n, u);
			break;
		}
		first[u] = cnt;
	}
	for (int i = 0; i < n; i++)
		if (u & 1 << i) cout << 1 << endl;
		else cout << 0 << endl;
	return 0;
}

