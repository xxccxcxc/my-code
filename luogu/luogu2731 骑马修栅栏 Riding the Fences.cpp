#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1050;
int n, ma[N][N];
vector<int> ans;

void dfs(int u) {
	for (int v = 1; v <= n; v++)
		if (ma[u][v]) {
			--ma[u][v]; --ma[v][u];
			dfs(v);
		}
	ans.push_back(u);
}

int main() {
	int m, d[N] = {0};
	scanf("%d", &m);
	for (int u, v; m--; ) {
		scanf("%d%d", &u, &v);
		++ma[u][v]; ++ma[v][u];
		++d[u]; ++d[v];
		n = max(n, max(u, v));
	}
	int st = 1;
	for (int i = 1; i <= n; i++)
		if (d[i] & 1) { st = i; break; }
	dfs(st);
	for (int siz = ans.size(), i = siz - 1; ~i; i--)
		printf("%d\n", ans[i]);
    return 0;
}

