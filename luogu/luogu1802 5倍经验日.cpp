#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int M = 1050;
int main() {
	int n, m, s = 0, f[M];
	memset(f, 0, sizeof(f));
	cin >> n >> m;
	for (int i = 1, lose, win, use; i <= n; i++) {
		cin >> lose >> win >> use;
		s += lose;
		win -= lose;
		for (int j = m; j >= use; j--)
			f[j] = max(f[j], f[j-use] + win);
	}
	cout << 1LL * (f[m] + s) * 5 << endl;
	return 0;
}

