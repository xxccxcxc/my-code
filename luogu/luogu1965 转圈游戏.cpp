#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
using namespace std;
long long n,m,k,x,tt;
long long ksm(long long t)
{
    if (t==1)return 10%n;
    tt=ksm(t/2)%n;
    if (t%2==0)return tt*tt;
    else return (tt*tt*10)%n;
}
int main()
{
    cin >>n>>m>>k>>x;
    cout <<(ksm(k)*m+x)%n;
    return 0;
}

