#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 100050;
vector<int> e[N];
int dfscnt, dfn[N], low[N];
bool iscut[N];

void tarjan(int u, int fa) {  // Tarjan¸îµã
	low[u] = dfn[u] = ++dfscnt;
	for (int siz = e[u].size(), i = 0, son = 0; i < siz; i++) {
		int v = e[u][i];
		if (!dfn[v]) {
			++son; tarjan(v, u);
			low[u] = min(low[u], low[v]);
			iscut[u] |= !fa && son > 1 || fa && low[v] >= dfn[u];
		}
		else if (v != fa) low[u] = min(low[u], dfn[v]);
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int u, v; m--; e[u].push_back(v), e[v].push_back(u))
		scanf("%d%d", &u, &v);
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i, 0);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += iscut[i];
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++)
		if (iscut[i]) printf("%d ", i);
	puts("");
    return 0;
}

