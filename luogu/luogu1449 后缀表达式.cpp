#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    string s;
    int qjs=0,tt=0;
    int a[10001]={0};
    cin >>s;
    for (int i=0;i<s.size()-1;i++)
    {
        if (s[i]>='0'&&s[i]<='9')qjs=qjs*10+s[i]-'0';
        else if (s[i]=='.'){a[++tt]=qjs;qjs=0;}
        else
        {
            if (s[i]=='+')a[--tt]+=a[tt+1];
            if (s[i]=='-')a[--tt]-=a[tt+1];
            if (s[i]=='*')a[--tt]*=a[tt+1];
            if (s[i]=='/')a[--tt]/=a[tt+1];
        }
    }
    cout <<a[tt];
    return 0;
}

