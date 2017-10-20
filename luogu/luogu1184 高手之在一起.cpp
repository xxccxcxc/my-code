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
    int n,m,ans=0;
    string a[25];
    scanf ("%d%d\n",&n,&m);
    if (n==1&&m==1){cout <<1;return 0;}
    for (int i=1;i<=n;i++)
      getline(cin,a[i]);
    for (int i=1;i<=m;i++)
    {
        string s;
        getline(cin,s);
        for (int j=1;j<=n;j++)
          if (s==a[j]){++ans;break;}
    }
    cout <<ans;
    return 0;
}

