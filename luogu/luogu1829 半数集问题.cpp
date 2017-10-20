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
int s=0;
int js(int a)
{
    ++s;
    for (int i=1;i<=a/2;i++)
      js(i);
}
int main()
{
    int n;
    cin >>n;
    js(n);
    cout <<s;
    return 0;
}

