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
int n,b[300];
char a[100][3];
bool p[300];
void dfs(int i)
{
    cout <<a[i][0];
    if (a[i][1]!='*')dfs(b[a[i][1]]);
    if (a[i][2]!='*')dfs(b[a[i][2]]);
}
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>a[i];
        b[a[i][0]]=i;
        ++p[a[i][1]];
        ++p[a[i][2]];
    }
    for (int i=1;i<=n;i++)
      if (!p[a[i][0]]){dfs(i);break;}
    return 0;
}

