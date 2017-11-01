#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 500050;
int n, tr[N]; // ��״���鱣�����ϢΪa[i]-a[i-1]������1~iǰ׺�͵õ��ľ���a[i] 

inline int lowbit(int x) {
	return x & (-x);
}

void add1(int pos, int val) { // �ѵ�pos��������val������a[pos]~a[n]����val�� 
	while (pos <= n) {
		tr[pos] += val;
		pos += lowbit(pos);
	}
}

void add(int l, int r, int val) { // ��a[l]~a[r]����val 
	add1(l, val);
	add1(r+1, -val);
}

int query(int pos) { // ����ǰpos�����ĺͣ���a[pos]�� 
	int ret = 0;
	while (pos) {
		ret += tr[pos];
		pos -= lowbit(pos);
	}
	return ret;
}

int main() {
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 1, pre = 0, r; i <= n; i++) {
		scanf("%d", &r);
		add1(i, r - pre);
		pre = r;
	}
	for (int opt; m--; ) {
		scanf("%d", &opt); 
		if (opt == 1) {
			int l, r, val;
			scanf("%d%d%d", &l, &r, &val);
			add(l, r, val);
		}
		else {
			int pos;
			scanf("%d", &pos);
			printf("%d\n", query(pos));
		} 
	}
    return 0;
}

