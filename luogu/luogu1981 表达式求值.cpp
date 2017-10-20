#include <iostream>
using namespace std;
int a[100002];
char c[100001];
int main()
{
    int g=0,t=0,ans=0;
    string s;
    cin >>s;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]>='0'&s[i]<='9')t=(t*10+s[i]-'0')%10000;
        else {a[++g]=t;c[g]=s[i];t=0;}
    }
    a[++g]=t;
    for (int i=1;i<g;i++)
    {
        if (c[i]=='*')
        {
            a[i+1]=(a[i]*a[i+1])%10000;
            a[i]=0;
        }
    }
    for (int i=1;i<=g;i++)ans=(ans+a[i])%10000;
    cout <<ans;
    return 0;
}
