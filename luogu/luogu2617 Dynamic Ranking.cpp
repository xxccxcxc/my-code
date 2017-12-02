#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 10050, M = 10050;

struct Opt {
	bool isQ;
	int l, r, k;
	int pos, val;
}opt[N*600];

struct Node {
	int ch[2], sum;
}tr[N*600];
int top = 1;

int n, a[N];
int rk[N<<1], dif;
int root[N];
vector<int> qNode[2];

int lowbit(int x) { return x & (-x); }

void update1(int &u, int L, int R, int pos, int val) {
	tr[u ? u : u = top++].sum += val;
	if (L == R) return;
	int mid = (L + R) >> 1;
	if (pos <= mid) update1(tr[u].ch[0], L, mid, pos, val);
	else update1(tr[u].ch[1], mid + 1, R, pos, val);
}

void update(int cur, int num, int val) {
	int pos = lower_bound(rk + 1, rk + dif + 1, num) - rk;
	for (int u = cur; u <= n; u += lowbit(u))
		update1(root[u], 1, dif, pos, val);
}

int kth1(int L, int R, int k) {
	if (L == R) return L;
	int mid = (L + R) >> 1, lCnt = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0, siz = qNode[i].size(); j < siz; j++)
			lCnt += tr[tr[qNode[i][j]].ch[0]].sum * (i ? 1 : -1);
	bool p = k > lCnt;
	for (int i = 0; i < 2; i++)
		for (int j = 0, siz = qNode[i].size(); j < siz; j++)
			qNode[i][j] = tr[qNode[i][j]].ch[p];
	return !p ? kth1(L, mid, k) : kth1(mid + 1, R, k - lCnt);
}

int kth(int l, int r, int k) {
	qNode[0].clear(); qNode[1].clear();
	for (int i = l - 1; i; i -= lowbit(i))
		qNode[0].push_back(root[i]);
	for (int i = r; i; i -= lowbit(i))
		qNode[1].push_back(root[i]);
	return rk[kth1(1, dif, k)];
}

int main() {
	ios::sync_with_stdio(false);
	int m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i], rk[++dif] = a[i];
	for (int i = 0; i < m; i++) {
		char ch; cin >> ch;
		if (opt[i].isQ = ch == 'Q') cin >> opt[i].l >> opt[i].r >> opt[i].k;
		else cin >> opt[i].pos >> opt[i].val, rk[++dif] = opt[i].val;
	}
	sort(rk + 1, rk + dif + 1);
	dif = unique(rk + 1, rk + dif + 1) - (rk + 1);
	for (int i = 1; i <= n; i++)
		update(i, a[i], 1);
	for (int i = 0; i < m; i++)
		if (opt[i].isQ)	cout << kth(opt[i].l, opt[i].r, opt[i].k) << endl;
		else update(opt[i].pos, a[opt[i].pos], -1), update(opt[i].pos, a[opt[i].pos] = opt[i].val, 1);
    return 0;
}

