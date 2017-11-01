#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 35;
int n, f[N][N], mid[N][N];

int getf(int l, int r) {
	return l > r ? 1 : f[l][r];
}

void print(int l, int r) {
	if (l > r) return;
	cout << mid[l][r] << ' ';
	print(l, mid[l][r] - 1);
	print(mid[l][r] + 1, r);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n;mid[i][i] = i, i++)
		cin >> f[i][i];
	for (int len = 2; len <= n; len++)
		for (int l = 1; l <= n - len + 1; l++)
			for (int r = l + len - 1, i = l; i <= r; i++) {
				int curf = getf(l, i-1) * getf(i+1, r) + f[i][i];
				if (curf > f[l][r]) {
					f[l][r] = curf;
					mid[l][r] = i;
				}
			}
	cout << f[1][n] << endl;
	print(1, n);
	cout << endl;
	return 0;
}

