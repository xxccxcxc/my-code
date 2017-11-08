#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100050, INF = 0x3f3f3f3f;
int ma[N], a[N], f[N];

int main() {
	int n; cin >> n;
	for (int i = 0, r; i < n; ma[r] = i++)
		cin >> r;
	for (int i = 0; i < n; i++)
		cin >> a[i], a[i] = ma[a[i]];
	memset(f, 0x3f, sizeof(f));
	for (int i = 0; i < n; i++)
		*lower_bound(f, f + n, a[i]) = a[i];
	cout << lower_bound(f, f + n, INF) - f << endl;
	return 0;
}

