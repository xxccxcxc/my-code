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
void xx(char &a)
{
    if (a>='A'&&a<='Z')a=a-'A'+'a';
}
int main()
{
    int p=-1,t=-1,as=0,i;
    string s,a;
    getline(cin,s);
    getline(cin,a);
    for (int i=0;i<s.size();i++)xx(s[i]);
    for (int i=0;i<a.size();i++)xx(a[i]);
    a+=" ";
    for (i=0;i<a.size();i++)
    {
        if (a[i]!=' ')continue;
        if (s==a.substr(t+1,i-t-1))
        {
            ++as;
            if (p==-1)p=t+1;
        }
        t=i;
    }
    if (as)cout <<as<<' ';
    cout <<p;
    return 0;
}
