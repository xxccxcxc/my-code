#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1000050, MOD = 1000000007;
int nxt[N], cnt[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int ls = s.size();
        s = '@' + s;
        memset(nxt, 0, sizeof(nxt));
        memset(cnt, 0, sizeof(cnt));
        cnt[1] = 1;
        for (int i = 2, k = 0; i <= ls; i++) {
            while (k && s[i] != s[k+1])
                k = nxt[k];
            if (s[i] == s[k+1]) ++k;
            nxt[i] = k;
            cnt[i] = cnt[k] + 1;
        }
        ll ans = 1;
        for (int i = 2, k = 0; i <= ls; i++) {
            while (k && s[i] != s[k+1])
                k = nxt[k];
            if (s[i] == s[k+1]) ++k;
            while (k * 2 > i)
                k = nxt[k];
            ans = (ans * ll(cnt[k] + 1)) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}

