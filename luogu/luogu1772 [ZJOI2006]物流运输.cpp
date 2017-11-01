#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 25, M = 105, INF = 0x3f3f3f3f;
int n, a[N][N];
bool clos[N][M];

int getDis(int st, int ed) {
	bool die[N] = {0};
	for (int i = 1; i <= n; i++)
		for (int j = st; j <= ed && !die[i]; j++)
			die[i] = clos[i][j];
	int dis[N][N];
	memcpy(dis, a, sizeof(dis));
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j && j != k && i != k && !die[i] && !die[j] && !die[k])
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	return dis[1][n] < INF ? dis[1][n] * (ed - st + 1) : dis[1][n];
}

int main() {
	int m, K, r;
	cin >> m >> n >> K >> r;
	memset(a, 0x3f, sizeof(a));
	while (r--) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u][v] = a[v][u] = min(a[u][v], w);
	}
	cin >> r;
	while (r--) {
		int u, st, ed;
		cin >> u >> st >> ed;
		for (int i = st; i <= ed; i++)
			clos[u][i] = true;
	}
	int f[M];
	for (int i = 1; i <= m; i++) {
		f[i] = getDis(1, i);
		for (int j = 1; j < i; j++)
			f[i] = min(f[i], f[j] + getDis(j+1, i) + K);
	}
	cout << f[m] << endl;
	return 0;
}


