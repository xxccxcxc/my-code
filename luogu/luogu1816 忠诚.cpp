#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath> 
using namespace std;
const int N = 1000050;
int n, m, f[N][30];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &f[i][0]);
	for (int j = 1; j <= log(n) / log(2); j++)
		for (int i = 1; i <= n - (1 << j) + 1; i++)
			f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
	for (int l, r; m--; ) {
		scanf("%d%d", &l, &r);
		int t = log(r - l + 1) / log(2);
		printf("%d ", min(f[l][t], f[r-(1<<t)+1][t]));
	}
	puts("");
	return 0;
}

