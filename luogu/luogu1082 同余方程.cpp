#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
void exgcd(int a, int b, int &x, int &y) { b ? (exgcd(b, a%b, y, x), y -= a / b * x) : (x = 1, y = 0); }
int main() {
	int a, b, x, y;
	cin >> a >> b;
	exgcd(a, b, x, y);
	cout << (x % b + b) % b << endl;
	return 0;
}

