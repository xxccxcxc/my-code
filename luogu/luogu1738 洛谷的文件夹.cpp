#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int N = 1000050;
map<string, int> ma[N];
int top;
int main() {
	int n; cin >> n;
	string s;
	for (int i = 1, ans = 0; i <= n; i++) {
		cin >> s; int len = s.size();
		for (int cur = 0, nxt = 0, u = 0; nxt != len; ) {
			cur = nxt; nxt = s.find('/', cur + 1);
			if (nxt < 0 || nxt > len) nxt = len;
			string a = s.substr(cur + 1, nxt - cur - 1);
			if (!ma[u].count(a)) ma[u][a] = ++top, ++ans;
			u = ma[u][a];
		}
		cout << ans << endl;
	}
	return 0;
}

