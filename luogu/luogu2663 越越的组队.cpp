#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 105, M = 10050;
int main() {
	int n, m = 0, a[N];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		m += a[i];
	}
	m /= 2;
	bool f[M] = {1};
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= a[i]; j--)
			f[j] |= f[j-a[i]];
	for (int i = m; i >= 0; i--)
		if (f[i]) { cout << i << endl; break; }
	return 0;
}

