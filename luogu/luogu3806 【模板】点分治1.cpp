#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 10050, D = 10000050;

struct Edge {
	int to, w, nxt;
	Edge(int _to=0, int _w=0, int _nxt=-1): to(_to), w(_w), nxt(_nxt) {}
}e[N<<1];
int ecnt, head[N];
int siz[N], mx[N], dtop, dis[N], dcnt[D];
bool vis[N];

void add(int u, int v, int w) {
	e[ecnt] = Edge(v, w, head[u]); head[u] = ecnt++;
	e[ecnt] = Edge(u, w, head[v]); head[v] = ecnt++;
}

int getroot(int u, int fa, int n) {
	siz[u] = 1; mx[u] = 0;
	int ret = 0;
	for (int i = head[u]; ~i; i = e[i].nxt) {
		int v = e[i].to;
		if (!vis[v] && v != fa) {
			int tmp = getroot(v, u, n);
			siz[u] += siz[v];
			mx[u] = max(mx[u], siz[v]);
			if (!ret || mx[tmp] < mx[ret])
				ret = tmp;
		}
	}
	mx[u] = max(mx[u], n - siz[u]);
	if (!ret || mx[u] < mx[ret]) ret = u;
	return ret;
}

void getdis(int u, int fa, int curdis) {
	dis[dtop++] = curdis;
	for (int i = head[u]; ~i; i = e[i].nxt) {
		int v = e[i].to;
		if (!vis[v] && v != fa)
			getdis(v, u, curdis + e[i].w);
	}
}

void work(int u, int t, int add) {
	dtop = 0;
	getdis(u, 0, 0);
	for (int i = 0; i < dtop; i++)
		for (int j = i+1; j < dtop; j++)
			if (dis[i] + dis[j] + t < D)
				dcnt[dis[i]+dis[j]+t] += add;
}

void dfs(int u, int n) {
	work(u, 0, 1);
	vis[u] = true;
	for (int i = head[u]; ~i; i = e[i].nxt) {
		int v = e[i].to;
		if (!vis[v]) {
			work(v, e[i].w << 1, -1);
			int vsiz = siz[v] <= siz[u] ? siz[v] : n - siz[u];
			dfs(getroot(v, 0, vsiz), vsiz);
		}
	}
}

int main() {
	memset(head, -1, sizeof(head));
	int n, m;
	scanf("%d%d", &n, &m);
	for (int u, v, w, i = 1; i < n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}
	int root = getroot(1, 0, 0);
	dfs(root, n);
	for (int d; m--; ) {
		scanf("%d", &d);
		printf(dcnt[d] ? "AYE\n" : "NAY\n");
	}
    return 0;
}

