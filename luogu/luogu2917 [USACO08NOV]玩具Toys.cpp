#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
const int N = 100050, INF = 0x3f3f3f3f;
struct Toys {
	int time, cnt;
	Toys(int _time = 0, int _cnt = 0): time(_time), cnt(_cnt) {}
};

int n, ds, df, cs, cf, c0, need[N];

int f(int x/*初始买多少玩具*/) {
	int ret = x * c0;
	queue<Toys> t;  // 还来不及洗的玩具 
	deque<Toys> fast;  // 可以快洗的 
	stack<Toys> slow;  // 可以慢洗的 
	for (int i = 1; i <= n; t.push(Toys(i, need[i])), i++) {
		while (!t.empty() && t.front().time <= i - df)
			fast.push_back(t.front()), t.pop();
		while (!fast.empty() && fast.front().time <= i - ds)
			slow.push(fast.front()), fast.pop_front();
		if (x >= need[i]) {
			x -= need[i];
			continue;
		}
		int rem = need[i] - x; x = 0;
		while (rem && !slow.empty()) {
			int tmp = min(rem, slow.top().cnt);
			ret += tmp * cs;
			slow.top().cnt -= tmp; rem -= tmp;
			if (!slow.top().cnt) slow.pop();
		}
		while (rem && !fast.empty()) {
			int tmp = min(rem, fast.back().cnt);
			ret += tmp * cf;
			fast.back().cnt -= tmp; rem -= tmp;
			if (!fast.back().cnt) fast.pop_back();
		}
		if (rem) return INF;
	}
	return ret;
}

int sf(int l, int r) {
	while (l + 3 < r) {
		int size = (r - l) / 3, mid1 = l + size, mid2 = mid1 + size;
		if (f(mid1) > f(mid2)) l = mid1;
		else r = mid2;
	}
	int ret = INF;
	for (int i = l; i <= r; i++)
		ret = min(ret, f(i));
	return ret;
}

int main() {
	scanf("%d%d%d%d%d%d", &n, &ds, &df, &cs, &cf, &c0);
	if (ds < df) swap(ds, df), swap(cs, cf);
	if (cs > cf) ds = df, cs = cf;
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &need[i]);
		l = max(l, need[i]);
		r += need[i];
	}
	printf("%d\n", sf(l, r));
	return 0;
}

