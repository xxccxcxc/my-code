#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 40050;
int main() {
	int n, a[N] = {0}, ans = 0;
	cin >> n;
	if (!--n) { cout << 0 << endl; return 0; }
	ans = a[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!a[i]) {
			a[i] = i;
			for (int j = i; j <= n; j += i) {
				if (!a[j]) a[j] = j;
				a[j] = a[j] * (i - 1) / i;
			}
		}
		ans += a[i];
	}
	cout << ans * 2 + 1 << endl;
    return 0;
}

