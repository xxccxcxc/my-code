#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 100, S = 60;
int main() {
	int n; cin >> n;
	LL a[S+5] = {0};
	for (int i = 1; i <= n; i++) {
		LL u; cin >> u;
		for (int j = S; ~j; j--)
			if (u & 1LL << j)
				if (!a[j]) { a[j] = u; break; }
				else u ^= a[j];
	}
	LL ans = 0;
	for (int i = S; ~i; i--)
		ans = max(ans, ans ^ a[i]);
	cout << ans << endl;
	return 0;
}

