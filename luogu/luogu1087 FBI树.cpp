#include <algorithm>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
int n;
string s;
void pd(string b)
{
    int B=1,I=1;
    for (int i=0;i<b.size();i++)
      if (b[i]=='0')I=0;
      else if (b[i]=='1')B=0;
    if (I)cout <<'I';
    else if (B)cout <<'B';
    else cout <<'F';
}
void dg(string a)
{
    if (a.size()>1)
    {
        dg(a.substr(0,a.size()/2));
        dg(a.substr(a.size()/2,a.size()/2));
    }
    pd(a);
}
int main()
{
    cin >>n>>s;
    dg(s);
    return 0;
}
