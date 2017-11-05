#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 100050, M = 200050;
struct Edge {
	int to, nxt;
	Edge(int _to=0, int _nxt=-1): to(_to), nxt(_nxt) {}
}e[M];
int ecnt, head[N];

void add(int u, int v) {
	e[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

int main() {
	memset(head, -1, sizeof(head));
	int n, m, in[N] = {0}, f[N] = {0};
	scanf("%d%d", &n, &m);
	for (int u, v; m--; add(u, v), ++in[v])
		scanf("%d%d", &u, &v);
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!in[i]) f[i] = 1, q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; ~i; i = e[i].nxt) {
			int v = e[i].to;
			f[v] = max(f[v], f[u] + 1);
			if (!--in[v]) q.push(v);
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", f[i]);
    return 0;
}

