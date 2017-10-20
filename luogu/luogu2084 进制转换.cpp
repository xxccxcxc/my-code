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
    string s;
    bool first=1;
    cin >>n>>s;
    for (int i=0;i<s.size();i++)
      if (s[i]!='0')
      {
            if (!first)cout <<'+';
            first=0;
            printf ("%d*%d^%d",s[i]-'0',n,s.size()-i-1);
      }
    return 0;
}

