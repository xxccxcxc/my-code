#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 40050;
int main() {
	int n; scanf("%d", &n); --n;
	int f[N] = {0, 1}, prime[N], pcnt = 0;
	for (int i = 2; i <= n; i++) {
		if (!f[i]) prime[pcnt++] = i, f[i] = i - 1;
		for (int j = 0; j < pcnt; j++) {
			if (i * prime[j] > n) break;
			if (i % prime[j] == 0) { f[i*prime[j]] = f[i] * prime[j]; break; }
			f[i*prime[j]] = f[i] * (prime[j] - 1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += f[i];
	printf("%d\n", ans << 1 | 1);
	return 0;
}

