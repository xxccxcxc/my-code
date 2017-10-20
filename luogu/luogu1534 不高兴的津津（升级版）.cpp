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
    int t=0,as=0,n,a,b;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>a>>b;
        t+=a+b-8;
        as+=t;
    }
    cout <<as;
    return 0;
}
