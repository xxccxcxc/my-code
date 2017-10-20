#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <utility>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <queue>
using namespace std;
int ts[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void getnum(string s,int &a,int &b,int &c)
{
    for (int i=0;i<=3;i++)a=a*10+s[i]-'0';
    b=(s[4]-'0')*10+s[5]-'0';
    c=(s[6]-'0')*10+s[7]-'0';
}
bool rn(int n)
{
    return (!(n%400))||(!(n%4)&&(n%100));
}
bool zao(int na,int ya,int ra,int nb,int yb,int rb)
{
    if (na<nb)return 1;
    if (na>nb)return 0;
    if (ya<yb)return 1;
    if (ya>yb)return 0;
    return ra<=rb;
}
bool hw(int n,int y,int r)
{
    int t1,t2;
    t1=n/1000;n%=1000;t2=r%10;r/=10;
    if (t1!=t2)return 0;
    t1=n/100;n%=100;t2=r;
    if (t1!=t2)return 0;
    t1=n/10;n%=10;t2=y%10;y/=10;
    if (t1!=t2)return 0;
    return n==y;
}
void xyg(int &n,int &y,int &r)
{
    ++r;
    if (r>ts[y])
    {
        r=1;
        ++y;//system ("pause");
        if (y>12)
        {
            y=1;
            ++n;
            if (rn(n))ts[2]=29;
            else ts[2]=28;
        }
    }
}
int main()
{
    string st,ed;
    cin >>st>>ed;
    int n=0,y=0,r=0,nb=0,yb=0,rb=0;
    getnum(st,n,y,r);
    getnum(ed,nb,yb,rb);
    int ans=0;
    if (rn(n))ts[2]=29;
    while (zao(n,y,r,nb,yb,rb))
    {
        if (hw(n,y,r))++ans;//cout <<n<<' '<<y<<' '<<r<<endl;
        xyg(n,y,r);
    }
    cout <<ans<<endl;
    return 0;
}


