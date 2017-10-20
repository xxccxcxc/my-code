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
    int n,m,w[4000],c[4000],f[15000]={0};
    cin >>n>>m;
    for (int i=1;i<=n;i++)
      cin >>w[i]>>c[i];
    for (int i=1;i<=n;i++)
      for (int j=m;j>=w[i];j--)
        f[j]=max(f[j],f[j-w[i]]+c[i]);
    cout <<f[m];
    return 0;
}

