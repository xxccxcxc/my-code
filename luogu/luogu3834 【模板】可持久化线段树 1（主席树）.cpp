#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 200050, INF = 1e9;

struct Node {
	int ls, rs, sum;
	Node(): ls(0), rs(0), sum(0) {}
}tr[N*40];
int top = 1, root[N];

void insert(int &cur, int pre, int val, int L, int R) {
	(tr[cur = top++] = tr[pre]).sum++;
	if (L == R) return;
	int mid = (L + R) >> 1;
	if (val <= mid) insert(tr[cur].ls, tr[pre].ls, val, L, mid);
	else insert(tr[cur].rs, tr[pre].rs, val, mid + 1, R);
}

int kth(int lu, int ru, int L, int R, int k) {
	if (L == R) return L;
	int lCnt = tr[tr[ru].ls].sum - tr[tr[lu].ls].sum, mid = (L + R) >> 1;
	if (k <= lCnt) return kth(tr[lu].ls, tr[ru].ls, L, mid, k);
	return kth(tr[lu].rs, tr[ru].rs, mid + 1, R, k - lCnt);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int t, i = 1; i <= n; i++) {
		scanf("%d", &t);
		insert(root[i], root[i-1], t, -INF, INF);
	}
	for (int l, r, k; m--; ) {
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", kth(root[l-1], root[r], -INF, INF, k));
	}
	return 0;
}

