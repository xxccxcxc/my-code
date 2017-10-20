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
unsigned long long b,p,k;
unsigned long long ksm(unsigned long long t)
{
    if (t==1)return b%k;
    unsigned long long tt=ksm(t/2);
    tt*=tt;
    if (t%2)tt*=b;
    return tt%k;
}
int main()
{
    cin >>b>>p>>k;
    cout <<b<<'^'<<p<<" mod "<<k<<'=';
    cout <<ksm(p);
    return 0;
}

