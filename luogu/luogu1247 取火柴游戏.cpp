#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 500050;
int n, a[N], s;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; s ^= a[i++])
		scanf("%d", &a[i]);
	if (!s) puts("lose");
	else {
		for (int i = 1; i <= n; i++)
			if ((a[i] ^ s) <= a[i]) {
				printf("%d %d\n", a[i] - (a[i] ^ s), i);
				a[i] = a[i] ^ s;
				break;
			}
		for (int i = 1; i <= n; i++)
			printf("%d ", a[i]);
		puts("");
	}
	return 0;
}

