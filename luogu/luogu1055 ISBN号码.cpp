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
    string a,b;
    int s=0;
    char t;
    cin >>b;
    a=b;
    a.erase(1,1);
    a.erase(4,1);
    a.erase(9,1);
    for (int i=0;i<9;i++)
      s+=(a[i]-'0')*(i+1);
    s%=11;
    if (s==10)
      t='X';
    else
      t=s+'0';
    if (t==a[9])
      cout <<"Right";
    else
    {
        b[12]=t;
        cout <<b;
    }
    return 0;
}
