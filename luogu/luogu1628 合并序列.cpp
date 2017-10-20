#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
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
#include <set>
using namespace std;
int main()
{
    int n,len;
    string s[100005],a;
    cin >>n;
    for (int i=1;i<=n;i++)cin >>s[i];
    cin >>a;len=a.size();
    sort (s+1,s+n+1);
    for (int i=1;i<=n;i++)
      if (s[i].substr(0,len)==a)
        cout <<s[i]<<endl;
    return 0;
}

