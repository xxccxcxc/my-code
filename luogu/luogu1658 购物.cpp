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
    int m,n,a[11],ans=0;
    cin >>m>>n;
    for (int i=1;i<=n;i++)cin >>a[i];
    sort (a+1,a+n+1);
    for (int i=1;i<=m;)
      for (int j=n;j>=1;j--)
        if (a[j]<=i){i+=a[j];++ans;break;}
    cout <<ans;
    return 0;
}

