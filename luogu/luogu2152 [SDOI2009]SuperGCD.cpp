#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int L = 10050, MX = 1e8;
struct Bigint {
    int len, num[L/8];
    
    Bigint() {
        len = 0;
        memset(num, 0, sizeof(num));
    }
    
    Bigint(string s) {
        memset(num, 0, sizeof(num));
        int siz = s.size();
        while (siz % 8) {
            s = '0' + s;
            ++siz;
        }
        len = siz/8;
        for (int i = 0; i < len; ++i) {
            int st = (len-i-1)*8;
            for (int j = 0; j < 8; ++j) {
                num[i] = num[i] * 10 + (s[st+j] - '0');
            }
        }
    }
    
    bool isEven() {
        return !(num[0]&1);
    }
    
    void print() {
        printf("%d", num[len-1]);
        for (int i = len-2; i >= 0; --i)
            printf("%08d", num[i]);
        printf("\n");
    }
    
    friend bool operator<(const Bigint &a, const Bigint &b) {
        if (a.len != b.len) return a.len < b.len;
        for (int i = a.len-1; i >= 0; --i)
            if (a.num[i] != b.num[i])
                return a.num[i] < b.num[i];
        return false;
    }
    
    friend bool operator!=(const Bigint &a, const Bigint &b) {
        return a < b || b < a;
    }
    
    void div2() {
        bool x = false;
        for (int i = len-1; i >= 0; --i) {
            int tmp = num[i];
            num[i] = (num[i] >> 1) + (x ? MX/2 : 0);
            x = tmp % 2;
        }
        while (len > 1 && !num[len-1])
            --len;
    }
    
    void mul2() {
        bool x = false;
        for (int i = 0; i < len; ++i) {
            num[i] = (num[i] << 1) + x;
            x = (num[i] >= MX);
            if (x) num[i] -= MX;
        }
        if (x) num[len++] = 1;
    }
    
    void operator-=(const Bigint &b) {
        for (int i = 0; i < len; ++i) {
            num[i] -= b.num[i];
            if (num[i] < 0) {
                num[i] += MX;
                --num[i+1];
            }
        }
        while (len > 0 && !num[len-1])
            --len;
    }
    
    friend Bigint gcd(Bigint a, Bigint b) {
        int cnt = 0;
        while (a != b) {
            while (a.isEven() && b.isEven()) {
                a.div2();
                b.div2();
                ++cnt;
            }
            while (a.isEven()) a.div2();
            while (b.isEven()) b.div2();
            if (a < b) b -= a;
            else if (b < a) a -= b;
        }
        while (cnt--) a.mul2();
        return a;
    }
};

int main() {
    string sa, sb;
    cin >> sa >> sb;
    Bigint a(sa), b(sb);
    gcd(a, b).print();
    return 0;
}

