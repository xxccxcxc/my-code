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
    int a[9] = {220,1184,2620,5020,6232,10744,12285,17296,63020};
    int b[9] = {284,1210,2924,5564,6368,10856,14595,18416,76084};
    cin >> n;
    for (int i = 0; i < 9; i++)
        if (n <= a[i])
        {
            cout << a[i] << ' '  << b[i] << endl;
            break;
        }
        else if (n <= b[i])
        {
            cout << b[i] << ' '  << a[i] << endl;
            break;
        }
    return 0;
}

