#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
int main()
{
    int t;
    cin >>t;
    while (t--)
    {
        string s;
        cin >>s;
        for (int i=0;i<s.size();i++)
          if (s[i]>'7')s[i]-=1;
          else if (s[i]=='7')
          {
                s[i]='6';
                for (int j=i+1;j<s.size();j++)
                  s[j]='9';
                break;
          }
        int t=1,ans=0;
        for (int i=s.size()-1;i>=0;i--)
        {
            ans+=(s[i]-'0')*t;
            t*=9;
        }
        cout <<ans<<endl;
    }
    return 0;
}

