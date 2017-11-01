#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 55, M = 5, INF = 0x3f3f3f3f;

struct Point {
	int x, y;
	bool operator<(const Point &t) const { return x < t.x; }
}a[N];

int main() {
	int n, m, s[N][N] = {0};
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i].y >> a[i].x;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1, high = a[i].y, low = a[i].y; j <= n; j++)
			s[i][j] = ((high = max(high, a[j].y)) - (low = min(low, a[j].y))) * (a[j].x - a[i].x);
	int f[N][N];
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++)
		f[i][1] = s[1][i];
	for (int k = 2; k <= m; k++)
		for (int i = 1; i <= n; i++)
			for (int j = k - 1; j < i; j++)
				f[i][k] = min(f[i][k], f[j][k-1] + s[j+1][i]);
	cout << f[n][m] << endl;
	return 0;
}

