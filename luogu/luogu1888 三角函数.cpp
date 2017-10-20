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
int gcd(int a,int b)
{
    if (!b)return a;
    return gcd(b,a%b);
}
int main()
{
    int a,b,c,d,e,g;
    cin >>a>>b>>c;
    d=min(a,min(b,c));
    e=max(a,max(b,c));
    g=gcd(d,e);
    d/=g;e/=g;
    cout <<d<<'/'<<e;
    return 0;
}

