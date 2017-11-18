#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 55, M = 500;
int main() {
	int m1, m2, n, f[M][M] = {0}, w1[N], w2[N], c[N];
	cin >> m1 >> m2 >> n;
	for (int i = 1; i <= n; i++)
		cin >> w1[i] >> w2[i] >> c[i];
	for (int i = 1; i <= n; i++)
		for (int j = m1; j >= w1[i]; j--)
			for (int k = m2; k >= w2[i]; k--)
				f[j][k] = max(f[j][k], f[j-w1[i]][k-w2[i]] + c[i]);
	cout << f[m1][m2] << endl;
	return 0;
}

