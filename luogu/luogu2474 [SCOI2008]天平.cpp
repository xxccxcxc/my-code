#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
int N = 55;
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    string sr;
    int mx[N][N], mn[N][N];
    for (int i = 1; i <= n; i++)
    {
        cin >> sr;
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            switch (sr[j-1])
            {
                case '?': mn[i][j] = -2; mx[i][j] = 2; break;
                case '+': mn[i][j] = 1; mx[i][j] = 2; break;
                case '-': mn[i][j] = -2; mx[i][j] = -1; break;
                default: mn[i][j] = mx[i][j] = 0;
            }
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j && j != k && i != k)
                {
                    mn[i][j] = max(mn[i][j], mn[i][k] + mn[k][j]);
                    mx[i][j] = min(mx[i][j], mx[i][k] + mx[k][j]);
                }
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (i != a && i != b && j != a && j != b)
            {
                c1 += (mn[a][i] > mx[j][b] || mn[a][j] > mx[i][b]);
                c2 += (mn[a][i] == mx[a][i] && mn[j][b] == mx[j][b] && mn[a][i] == mn[j][b] || \
                       mn[a][j] == mx[a][j] && mn[i][b] == mx[i][b] && mn[a][j] == mn[i][b]);
                c3 += (mn[i][a] > mx[b][j] || mn[j][a] > mx[b][i]);
            }
    cout << c1 << ' ' << c2 << ' ' << c3 << endl;
    return 0;
}

