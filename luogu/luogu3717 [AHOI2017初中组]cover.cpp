#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <algorithm>
#include <bitset>
#include <map>
#include <set>
using namespace std;
int main()
{
    bool p[200][200] = {0};
    int n, m, r, ans = 0;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (!p[j][k] && ((j-x) * (j-x) + (k-y) * (k-y) - r * r <= 0))
                    p[j][k] = true, ++ans;
    }
    cout << ans << endl;
    return 0;
}

