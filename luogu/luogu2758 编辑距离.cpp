#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int L = 2050;
int f[2][L];
int main() {
	string a, b;
	cin >> a >> b;
	int la = a.size(), lb = b.size();
	a = " " + a; b = " " + b;
	memset(f, 0x3f, sizeof(f));
	for (int j = 0; j <= lb; j++)
		f[0][j] = j;
	for (int i = 1; i <= la; i++) {
		int cur = i & 1, pre = cur ^ 1;
		memset(f[cur], 0x3f, sizeof(f[cur]));
		f[cur][0] = i;
		for (int j = 1; j <= lb; j++) {
			if (a[i] == b[j]) f[cur][j] = f[pre][j-1];
			f[cur][j] = min(f[cur][j], f[pre][j-1] + 1);
			f[cur][j] = min(f[cur][j], f[pre][j] + 1);
			f[cur][j] = min(f[cur][j], f[cur][j-1] + 1);
		}
	}
	cout << f[la&1][lb] << endl;
	return 0;
}

