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
int main()
{
    int k,n=0,ans=0;
    cin >>k;
    for (int i=1;;i++)
    {
        if (n+i<=k){n+=i;ans+=i*i;}
        else {ans+=i*(k-n);break;}
    }
    cout <<ans;
    return 0;
}

