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
    int n,s=1;
    cin >>n;
    for (int i=1;i<=n;i++)s=(4*i-2)*s/(i+1);
    cout <<s;
    return 0;
}
