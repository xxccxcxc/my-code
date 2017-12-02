#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
int m, n, ans;

void dfs(int cur, int pre, int rem) {
	if (cur == n) { ans += !rem; return; }
	if ((n - cur) * pre > rem) return;
	for (int i = pre; i <= rem; i++)
		dfs(cur + 1, i, rem - i);
}

int main() {
	int T; cin >> T;
	while (T--) {
		cin >> m >> n;
		ans = 0; dfs(0, 0, m);
		cout << ans << endl;
	}
	return 0;
}

