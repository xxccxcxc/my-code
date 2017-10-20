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
    int a=0,b=0,n,r;
    cin >>n;
    while (n--)
    {
        cin >>r;
        if (r==5)++a;
        else ++b;
    }
    a=(a/9)*9;
    if (b==0){cout <<-1;return 0;}
    for (int i=1;i<=a;i++)cout <<5;
    if (a)for (int i=1;i<=b;i++)cout <<0;
    else cout <<0;
    return 0;
}
