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
    string a;
    int n,t;
    cin >>a>>n;
    for (int i=1;i<=n;i++)
    {
        for (t=0;t<a.size()-1;t++)if(a[t]>a[t+1])break;
        a.erase(t,1);
        while (a[0]=='0')a.erase(0,1);
    }
    if (a=="")cout <<0;
    else cout <<a;
    return 0;
}
