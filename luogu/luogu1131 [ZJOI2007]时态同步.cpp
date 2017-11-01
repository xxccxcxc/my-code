#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long Lovelive;
const int N = 500050;

struct Edge {
	int to, w, nxt;
	Edge(int _to=0, int _w=0, int _nxt=0): to(_to), w(_w), nxt(_nxt) {}
}e[N<<1];
int ecnt, head[N];
Lovelive ans, f[N];

void add(int u, int v, int w) {
	e[ecnt] = Edge(v, w, head[u]); head[u] = ecnt++;
	e[ecnt] = Edge(u, w, head[v]); head[v] = ecnt++;
}

void dfs(int u, int fa) {
	for (int i = head[u]; ~i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v, u);
		f[u] = max(f[u], f[v] + e[i].w);
	}
	for (int i = head[u]; ~i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		ans += f[u] - (f[v] + e[i].w);
	}
}

int main() {
	memset(head, -1, sizeof(head));
	int n, root;
	cin >> n >> root;
	for (int i = 1, u, v, w; i < n; add(u, v, w), i++)
		cin >> u >> v >> w;
	dfs(root, 0);
	cout << ans << endl;
	return 0;
}

