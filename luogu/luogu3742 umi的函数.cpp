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
    int n;
    string x, y;
    bool fail = false;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
        if (x[i] < y[i])
        {
            fail = true;
            break;
        }
    if (fail) cout << -1 << endl;
    else      cout << y;
    return 0;
}

