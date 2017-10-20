#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    string a;
    int n;
    char p;
    cin >>n>>a;
    n%=26;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]+n>'Z'&&a[i]+n<'a'||a[i]+n>'z'||a[i]+n<'A')
          a[i]=a[i]+n-26;
        else
          a[i]=a[i]+n;
    }
    cout <<a;
    return 0;
}
