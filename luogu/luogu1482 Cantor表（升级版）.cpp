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
    int a,b,c,d,e,f,g;
    scanf ("%d/%d%d/%d",&a,&b,&c,&d);
    e=a*c;f=b*d;g=gcd(e,f);
    e/=g;f/=g;
    cout <<f<<' '<<e;
    return 0;
}

