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
    bool a[500001]={0};
    int n,b;
    double t;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>t>>b;
        for (int j=1;j<=b;j++)a[(int)(j*t)]=!a[(int)(j*t)];
    }
    for (int i=1;i<=1000000;i++)
    {
        if (a[i]){cout <<i;break;}
    }
    return 0;
}
