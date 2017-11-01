#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int N = 10050;
int n;
vector<int> edge[N];
int dfscnt, dfn[N], low[N];
bool able[N];
int bcnt, belong[N], siz[N];
stack<int> st;

void tarjan(int u) {
	st.push(u);
	dfn[u] = low[u] = ++dfscnt;
	able[u] = true;
	for (int i = 0, tote = edge[u].size() ; i < tote; i++) {
		int v = edge[u][i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (able[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++bcnt;
		while (!st.empty()) {
			int tmp = st.top(); st.pop();
			++siz[belong[tmp] = bcnt];
			able[tmp] = false;
			if (tmp == u) break;
		}
	}
}

int main() {
	int m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	int out[N] = {0};
	for (int u = 1; u <= n; u++)
		for (int i = 0, tote = edge[u].size() ; i < tote; i++) {
			int v = edge[u][i];
			if (belong[u] != belong[v])
				++out[belong[u]];
		}
	int ans = 0;
	for (int i = 1; i <= bcnt; i++)
		if (!out[i]) {
			if (ans) {
				ans = -1;
				break;
			}
			ans = i;
		}
	if (ans != -1) cout << siz[ans] << endl;
	else cout << 0 << endl;
	return 0;
}

