#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
using namespace std;
typedef unsigned long long ULL;
const ULL SEED1 = 131, SEED2 = 163;
const int MAXN = 10050;
struct Node
{
    int h1, h2;
    bool operator <(Node v)
    {
        return h1 < v.h1 || h1 == v.h1 && h2 < v.h2;
    }
    bool operator !=(Node v)
    {
        return h1 != v.h1 || h2 != v.h2;
    }
};

ULL hash(string s, ULL seed)
{
    ULL ret = 0;
    for (int i = 0; i < s.size(); i++)
        ret = ret * seed + s[i];
    return ret;
}

int main()
{
    int n;
    Node hashed[MAXN];
    cin >> n; 
    for (int i = 0; i < n; ++i)
    {
        string r;
        cin >> r;
        hashed[i].h1 = hash(r, SEED1);
        hashed[i].h2 = hash(r, SEED2);
    }
    sort(hashed, hashed + n);
    int ans = 1;
    for (int i = 1; i < n; ++i)
        if (hashed[i] != hashed[i-1])
            ++ans;
    cout << ans << endl;
    return 0;
}


