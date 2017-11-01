#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

struct Matrix {
	static const int MOD = 1e9+7;
	static const int N = 105;
	LL mat[N][N];
	int n, m;
	
	Matrix(int _n=0, int _m=0): n(_n), m(_m) {
		memset(mat, 0, sizeof(mat));
	}
	
	Matrix operator*(const Matrix &b) const {
		if (m != b.n) {
			cout << "operator* error" << endl;
			return Matrix();
		}
		Matrix ret(n, b.m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < b.m; j++)
				for (int k = 0; k < m; k++)
					ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * b.mat[k][j]) % MOD;
		return ret;
	}
	
	Matrix operator*=(const Matrix &b) {
		*this = *this * b;
		return *this;
	}
	
	Matrix operator^(LL k)const {
		Matrix tmp = *this, ret = *this;
		for (--k; k; k >>= 1, tmp *= tmp)
			if (k & 1) ret *= tmp;
		return ret;
	}
	
	friend istream& operator>>(istream &in, Matrix &t) {
		for (int i = 0; i < t.n; i++)
			for (int j = 0; j < t.m; j++)
				in >> t.mat[i][j];
		return in;
	}
};

int read() { int tmp; cin >> tmp; return tmp; }

int main() {
	Matrix base(3, 3);
	base.mat[0][0] = base.mat[0][1] = base.mat[1][2] = base.mat[2][0] = 1;
	for (int T = read(), n; T--; ) {
		cin >> n;
		if (n <= 3) cout << 1 << endl;
		else {
			Matrix t = base ^ (n-3);
			cout << (t.mat[0][0] + t.mat[1][0] + t.mat[2][0]) % t.MOD << endl;
		}
	}
	return 0;
}

