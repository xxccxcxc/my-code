#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 100050;
LL b[N], c[N];
int siz;

int lowbit(int x) { return x & (-x); }

void add1(LL *t, int pos, int val) {
	for (; pos <= siz; pos += lowbit(pos))
		t[pos] += val;
}

void add(int l, int r, LL val) {
	add1(b, l, val); add1(b, r+1, -val);
	add1(c, l, val * (l-1)); add1(c, r+1, -val * r);
}

LL query1(LL *t, int pos) {
	LL ret = 0;
	for (; pos; pos -= lowbit(pos))
		ret += t[pos];
	return ret;
}

LL query(int l, int r) {
	LL s1 = (l-1) * query1(b, l-1) - query1(c, l-1), s2 = r * query1(b, r) - query1(c, r);
	return s2 - s1;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	siz = n;
	for (int i = 1; i <= n; i++) {
		LL val;
		scanf("%lld", &val);
		add(i, i, val);
	}
	for (int opt, l, r; m--; ) {
		scanf("%d%d%d", &opt, &l, &r);
		if (opt == 1) {
			LL val;
			scanf("%lld", &val);
			add(l, r, val);
		}
		else printf("%lld\n", query(l, r));
	}
    return 0;
}

