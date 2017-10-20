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
    int a,b,c,t1=1,t2=1,t3=1;
    cin >>a>>b>>c;
    for (int i=1;i<=c/2;i++)t3*=a;
    for (int i=1;i<=b;i++)t1*=2;
    for (int i=1;i<=c/2;i++)t2*=3;
    cout <<a*t1+a*t2+t3;
    return 0;
}

