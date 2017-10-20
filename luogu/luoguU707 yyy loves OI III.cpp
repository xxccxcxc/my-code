#include <algorithm>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
int n,a[1001][1001],b[1001];
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
          cin >>a[i][j];
        sort (a[i]+1,a[i]+n+1);
        b[i]=a[i][n/2+1];
    }
    sort (b+1,b+n+1);
    cout <<b[n/2+1];
    return 0;
}
