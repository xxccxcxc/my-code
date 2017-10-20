#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
int n,a[10000000],t;
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++){scanf ("%d",&t);++a[t];}
    for (int i=1;i<=10000000;i++){if (a[i]%2){cout <<i;break;}}
    return 0;
}

