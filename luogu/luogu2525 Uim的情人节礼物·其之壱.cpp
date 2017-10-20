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
    int a[20],n;
    cin >>n;
    for (int i=1;i<=n;i++)cin >>a[i];
    if (!prev_permutation(a+1,a+n+1))cout <<"ERROR";
    else for (int i=1;i<=n;i++)cout <<a[i]<<' ';
    return 0;
}

