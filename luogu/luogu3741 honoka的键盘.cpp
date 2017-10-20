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
    int n, vk = 0, ans;
    string a;
    cin >> n >> a;
    for (int i = 0; i < n - 1; i++)
        vk += (a[i] == 'V' && a[i+1] == 'K');
    ans = vk;
    for (int i = 0; i < n; i++)
    {
        string b = a;
        if (b[i] == 'V') b[i] = 'K';
        else b[i] = 'V';
        vk = 0;
        for (int j = 0; j < n - 1; j++)
            vk += (b[j] == 'V' && b[j+1] == 'K');
        ans = max(ans, vk);
    }
    cout << ans << endl;
    return 0;
}

