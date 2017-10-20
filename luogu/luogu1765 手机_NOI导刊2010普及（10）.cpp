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
    int as=0,a[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    getline(cin,s);
    for (int i=0;i<s.size();i++)
      if (s[i]==' ')
        ++as;
      else
        as+=a[s[i]-'a'];
    cout <<as;
    return 0;
}
