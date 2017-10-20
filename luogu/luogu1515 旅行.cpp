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
    int a[50] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    int A, B, n = 14, m;
    cin >> A >> B >> m;
    for (int i = 0; i < m; i++)
        cin >> a[n++];
    sort(a, a + n);
    int f[50] = {1};
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i && a[i] - a[j] >= A; j++)
            if (a[i] - a[j] <= B)
                f[i] += f[j];
    cout << f[n-1];
    return 0;
}

