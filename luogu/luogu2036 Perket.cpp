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
const int INF = 0x3f3f3f3f;
int main()
{
    int n, a[20], b[20], ans = INF;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for (int i = 1; i < (1 << n); i++)
    {
        int s = 1, t = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
            {
                s *= a[j];
                t += b[j];
            }
        ans = min(ans, abs(s - t));
    }
    cout << ans << endl;
    return 0;
}

