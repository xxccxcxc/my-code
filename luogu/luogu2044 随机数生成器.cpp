#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL mod;

LL mul(LL a, LL b) {
    LL ret = 0;
    for (; b; b >>= 1, a = (a+a)%mod)
        if (b & 1) ret = (ret+a)%mod;
    return ret;
}

class Matrix {
    
public:
    
    static const int N = 105;
    LL mat[N][N];
    int n, m;
    
    Matrix(int _n=0, int _m=0) {
        n = _n; m = _m;
        memset(mat, 0, sizeof(mat));
    }
    
    Matrix operator*(const Matrix &b)const {
        if (m != b.n) {
            cout << "operator* error\n";
            return Matrix();
        }
        Matrix ret(n, b.m);
        for (int i = 0; i < ret.n; i++)
            for (int j = 0; j < ret.m; j++)
                for (int k = 0; k < m; k++)
                    ret.mat[i][j] = (ret.mat[i][j] + mul(mat[i][k], b.mat[k][j])) % mod;
        return ret;
    }
    
    Matrix operator*=(const Matrix &b) {
        *this = *this * b;
        return *this;
    }
    
    Matrix operator^(LL k)const {
        Matrix tmp = *this, ret = *this;
        for (--k; k; k >>= 1, tmp *= tmp)
            if (k & 1)
                ret *= tmp;
        return ret;
    }
    
    Matrix operator^=(LL k) {
        *this = *this ^ k;
        return *this;
    }
    
    friend istream& operator>>(istream&, Matrix&);
    friend ostream& operator<<(ostream&, const Matrix&);
};

istream& operator>>(istream &in, Matrix &a) {
    for (int i = 0; i < a.n; i++)
        for (int j = 0; j < a.m; j++)
            in >> a.mat[i][j];
    return in;
}

ostream& operator<<(ostream &out, const Matrix &a) {
    for (int i = 0; i < a.n; i++) {
        for (int j = 0; j < a.m; j++)
            out << a.mat[i][j] << ' ';
        out << endl;
    }
    return out;
}

int main() {
    LL a, c, x0, n, g;
    cin >> mod >> a >> c >> x0 >> n >> g;
    Matrix t(2, 2);
    t.mat[0][0] = a;
    t.mat[1][0] = t.mat[1][1] = 1;
    t ^= n;
    Matrix ans(1, 2);
    ans.mat[0][0] = x0;
    ans.mat[0][1] = c;
    ans *= t;
    cout << (ans.mat[0][0] % g + g) % g;
    return 0;
}

