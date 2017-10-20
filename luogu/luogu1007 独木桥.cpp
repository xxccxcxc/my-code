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
    int l,n,a,max=0,min=0,d,x;
    cin >>l>>n;
    for (int i=1;i<=n;i++)
    {
        cin >>a;
        d=l+1-a>a?l+1-a:a;
        x=l+1-a<a?l+1-a:a;
        if (d>max) max=d;
        if (x>min) min=x;
    }
    cout <<min<<' '<<max;
    return 0;
}
