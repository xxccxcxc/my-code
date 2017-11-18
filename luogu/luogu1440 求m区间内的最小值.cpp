#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <deque>
#include <utility>
using namespace std;
deque< pair<int, int> > q;
char ch[25];

int read() {
	char ch; int x, sgn = 1;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') sgn = -1;
	for (x = 0; isdigit(ch); ch = getchar())
		x = x * 10 + ch - '0';
	return x * sgn;
}

void write(int x) {
	if (!x) { putchar('0'); return; }
	int len = 0;
	if (x < 0) putchar('-'), x = -x;
	for (; x; x /= 10) ch[len++] = x % 10 + '0';
	for (int i = len - 1; ~i; i--) putchar(ch[i]);
}

int main() {
    int n = read(), m = read();
    for (int i = 1, t; i <= n; i++) {
        while (!q.empty() && q.front().first < i - m) q.pop_front();
        if (!q.empty()) write(q.front().second);
        else putchar('0');
        putchar('\n');
        t = read();
        while (!q.empty() && q.back().second > t) q.pop_back();
        q.push_back(make_pair(i, t));
    } 
    return 0;
}
