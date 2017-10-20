#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
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
#include <set>
using namespace std;
int main()
{
    string s;
    cin >>s;
    s+="    ";
    int b=0,g=0;
    for (int i=0;i<s.size()-4;i++)
    {
        if (s[i]=='b'||s[i+1]=='o'||s[i+2]=='y')++b;
        if (s[i]=='g'||s[i+1]=='i'||s[i+2]=='r'||s[i+3]=='l')++g;
    }
    cout <<b<<endl<<g;
    return 0;
}

