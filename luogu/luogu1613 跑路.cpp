#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 55, D = 64;
int n, m, dis[N][N];
bool a[N][N][D+5];
int main() {
	memset(dis, 0x3f, sizeof(dis));
	scanf("%d%d", &n, &m);
	for (int u, v; m--; ) {
		scanf("%d%d", &u, &v);
		a[u][v][0] = true;
		dis[u][v] = 1;
	}
	for (int t = 1; t <= D; t++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					if (a[i][k][t-1] && a[k][j][t-1]) {
						a[i][j][t] = true;
						dis[i][j] = 1;
					}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j && j != k && i != k)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	printf("%d\n", dis[1][n]);
	return 0;
}

