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
    string s;
    int c,a[5002],x=0,w1,w2=1,t;
    cin >>s>>c;
    w1=s.size();
    for (int i=1;i<=w1;i++)
    {
        t=s[i-1]-'0';
        a[i]=(x*10+t)/c;
        x=(x*10+t)%c;
    }
    while (!a[w2]&&w2<w1)++w2;
    for (int i=w2;i<=w1;i++)cout <<a[i];
    return 0;
}
