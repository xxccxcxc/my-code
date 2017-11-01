#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 20050;
int SG(int a, int b) {
	int ret = 0;
	while (!(a & 1) || !(b & 1)) {
		a += a & 1; b += b & 1;
		while (!(a & 1) && !(b & 1))
			a >>= 1, b >>= 1, ++ret;
	}
	return ret;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int n; T--; ) {
		scanf("%d", &n);
		int s = 0;
		for (int i = 1, a, b; i * 2 <= n; s ^= SG(a, b), i++)
			scanf("%d%d", &a, &b);
		printf(s ? "YES\n" : "NO\n");
	} 
	return 0;
}

