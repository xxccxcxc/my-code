#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
const int N = 250, INF = 0x3f3f3f3f;
int main() {
	int n, a[N][N], f[N];
	cin >> n;
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			cin >> a[i][j];
	memset(f, 0x3f, sizeof(f));
	f[1] = 0;
	for (int j = 2; j <= n; j++)
		for (int i = 1; i < j; i++)
			f[j] = min(f[j], f[i] + a[i][j]);
	cout << f[n] << endl;
	return 0;
}

