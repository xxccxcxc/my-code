#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 11000050;
char sr[N], s[N*2];
int len[N*2];
int manacher(int n, char *a)
{
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
        ans = max(ans, len[i]);
    }
    return ans-1;
}
int main()
{
    scanf("%s", sr);
    int n = strlen(sr);
    s[0] = '$';
    s[1] = '#';
    for (int i = 0; i < n; i++)
    {
        s[i*2+2] = sr[i];
        s[i*2+3] = '#';
    }
    n = n*2+3;
    s[n-1] = '@';
    s[n] = '\0';
    cout << manacher(n, s) << endl;
    return 0;
}

