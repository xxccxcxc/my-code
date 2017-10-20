#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int MOD = 1000000007;
int f1[250][250], f2[250][250];
int main()
{
    int la, lb, m;
    string a, b;
    cin >> la >> lb >> m >> a >> b;
    f2[0][0] = 1;
    for (int i = 1; i <= la; i++)
        for (int j = lb; j; j--)
            for (int k = m; k; k--)
                if (a[i-1] == b[j-1])
                {
                    f1[j][k] = (f1[j-1][k] + f2[j-1][k-1]) % MOD;
                    f2[j][k] = (f2[j][k] + f1[j][k]) % MOD;
                }
                else f1[j][k] = 0;
    cout << f2[lb][m] << endl;
    return 0;
}

