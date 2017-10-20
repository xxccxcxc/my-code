#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin >>s;
        if ((s[s.size()-1]-'0')%2)cout <<"odd\n";
        else cout <<"even\n";
    }
    return 0;
}

