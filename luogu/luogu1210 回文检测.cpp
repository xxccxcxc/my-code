#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 50050;
string init(const string &a, int *ma)
{
    int n = a.size();
    string s = "";
    s += "$#";
    int cur = 2;
    for (int i = 0; i < n; i++)
        if (isalpha(a[i]))
        {
            ma[cur] = i;
            s += tolower(a[i]);
            s += '#';
            cur += 2;
        }
    s += "@";
    return s;
}
int manacher(const string &a, int &pos)
{
    int n = a.size(), len[N] = {0};
    int id = 0, mx = 0, ans = 0;
    for (int i = 1; i < n-1; i++)
    {
        len[i] = 1;
        if (i < mx)
            len[i] = min(len[id*2-i], mx-i);
        while (a[i+len[i]] == a[i-len[i]])
            ++len[i];
        if (i+len[i] > mx)
            mx = i+len[i], id = i;
        if (len[i] > ans)
            ans = len[i], pos = i;
    }
    return ans-1;
}
int main()
{
    string sr;
    char ch;
    while (~(ch = getchar()))
        sr += ch;
    int ma[N], pos;
    string a = init(sr, ma);
    int ans = manacher(a, pos);
    int st = ma[pos-ans+1], ed = ma[pos+ans-1];
    string ansStr = sr.substr(st, ed-st+1);
    cout << ans << endl << ansStr << endl;
    return 0;
}

