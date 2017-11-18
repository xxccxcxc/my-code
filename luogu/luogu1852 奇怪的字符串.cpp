#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int L = 10050;
int main() {
	string a, b;
	cin >> a >> b;
	int la = a.size(), lb = b.size();
	a = ' ' + a; b = ' ' + b;
	int f[2][L]; memset(f, 0, sizeof(f));
	for (int i = 1; i <= la; i++)
		for (int j = 1, cur = i % 2, pre = (i - 1) % 2; j <= lb; j++)
			f[cur][j] = a[i] == b[j] ? f[pre][j-1] + 1 : max(f[pre][j], f[cur][j-1]);
	cout << f[la%2][lb] << endl;
	return 0;
}

