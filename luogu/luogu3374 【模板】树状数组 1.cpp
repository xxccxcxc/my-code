#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 500050;
int n, tr[N];

inline int lowbit(int x) {
	return x & (-x);
}

void add(int pos, int val) {
	while (pos <= n) {
		tr[pos] += val;
		pos += lowbit(pos);
	}
}

int query1(int pos) {
	int ret = 0;
	while (pos) {
		ret += tr[pos];
		pos -= lowbit(pos);
	}
	return ret;
}

int query(int l, int r) {
	return query1(r) - query1(l-1);
}

int main() {
	int m;
	scanf("%d%d", &n, &m);
	/*for (int i = 1; i <= n; i++)
		scanf("%d", &tr[i]);
	这里不能直接输入tr[i]，因为树状数组初值不等于原数组初值。*/
	for (int i = 1, r; i <= n; i++) {
		scanf("%d", &r);
		add(i, r);
	} 
	for (int opt, r1, r2; m--; ) {
		scanf("%d%d%d", &opt, &r1, &r2);
		if (opt == 1) add(r1, r2);
		else printf("%d\n", query(r1, r2));
	}
    return 0;
}

