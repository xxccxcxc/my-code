#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 10000050;
bool p[N];
int prime[N], pcnt;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	p[1] = true;
	for (int i = 2; i <= n; i++) {
		if (!p[i]) prime[pcnt++] = i;
		for (int j = 0; j < pcnt; j++) {
			if (i * prime[j] > n) break;
			p[i*prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
	for (int r; m--; printf(p[r] ? "No\n" : "Yes\n"))
		scanf("%d", &r);
	return 0;
}

