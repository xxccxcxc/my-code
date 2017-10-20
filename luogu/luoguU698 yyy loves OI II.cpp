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
int main()
{
    int n,l,k,a[1001],s=0;
    cin >>n>>l>>k;
    for (int i=1;i<=n;i++)cin >>a[i];
    sort (a+1,a+n+1);
    for (int i=1;i<=n;i++)if (l>=a[i]){++s;l+=k;}
    cout <<s;
    return 0;
}
