#include <iostream>  
#include <iomanip>  
#include <cstdio>  
#include <cstdlib>  
#include <algorithm>  
#include <cstring>  
#include <string>  
#include <vector>  
#include <cmath>  
#include <ctime>  
#include <queue>  
#include <stack>  
using namespace std;  
vector <int> c[31];  
int n;  
void fb(int a,int &p,int &h)  
{  
    for (p=0;p<n;p++)  
      for (h=0;h<c[p].size();h++)  
        if (c[p][h]==a)return;  
}  
void ca(int p,int h)  
{  
    for (int i=h+1;i<c[p].size();i++)  
      c[c[p][i]].push_back(c[p][i]);  
    c[p].resize(h+1);  
}  
void po(int p,int h,int p2)  
{  
    for (int i=h;i<c[p].size();i++)  
      c[p2].push_back(c[p][i]);  
    c[p].resize(h);  
}  
int main()  
{  
    ios::sync_with_stdio(false);  
    int a,b;  
    string s1,s2;  
    cin >>n;  
    for (int i=0;i<n;i++)c[i].push_back(i);  
    while (cin >>s1>>a>>s2>>b)  
    {  
        if (s1=="quit")break;  
        int pa,pb,ha,hb;  
        fb(a,pa,ha);  
        fb(b,pb,hb);  
        if (pa==pb)continue;  
        if (s1=="move")ca(pa,ha);  
        if (s2=="onto")ca(pb,hb);  
        po(pa,ha,pb);  
    }  
    for (int i=0;i<n;i++)  
    {  
        cout <<i<<':';  
        for (int j=0;j<c[i].size();j++)  
          cout <<' '<<c[i][j];  
        cout <<endl;  
    }  
    return 0;  
}  

