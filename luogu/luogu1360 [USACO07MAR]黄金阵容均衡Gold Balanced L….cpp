#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
map<vector<int>, int> ma;
int main() {
	//freopen("balance.in", "r", stdin);
	//freopen("balance.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> cur(m);
	int ans = 0;
	ma[cur] = 1;
	for (int i = 2, t; i <= n + 1; i++) {
		scanf("%d", &t);
		for (int j = 0; j < m; j++)
			if (t & 1 << j) ++cur[j];
		if (t & 1) for (int j = 0; j < m; j++) --cur[j];
		if (ma.count(cur)) ans = max(ans, i - ma[cur]);
		else ma[cur] = i;
	}
	printf("%d\n", ans);
	return 0;
}

