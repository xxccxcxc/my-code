#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    unsigned long long s1,f1,m1,s2,f2,m2,s;
    int n;
    scanf ("%I64d:%I64d:%I64d%I64d:%I64d:%I64d%d",&s1,&f1,&m1,&s2,&f2,&m2,&n);
    s=((s2-s1)*3600+(f2-f1)*60+(m2-m1))*n;
    cout <<s;
    return 0;
}
