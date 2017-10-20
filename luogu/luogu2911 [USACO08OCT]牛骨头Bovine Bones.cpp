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
    int s[100] = {0}, a, b, c, m = 0;
    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k <= c; k++)
                ++s[i+j+k];
    for (int i = 0; i < a + b + c; i++)
        if (s[i] > s[m])
            m = i;
    cout << m << endl;
    return 0;
}

