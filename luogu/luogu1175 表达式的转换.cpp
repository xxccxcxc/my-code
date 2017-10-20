#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
char a[1000000],b[1000000],z[1000000];
int c[1000000],n,m,top;
bool cz(char x,char y)
{
    if (x=='(')return 0;
    if (x=='^')return 1;
    if (y=='^')return 0;
    if (x=='*'||x=='/')return 1;
    if (y=='*'||y=='/')return 0;
    return 1;
}
int js(int x,int y,char p)
{
    if (p=='+')return x+y;
    if (p=='-')return x-y;
    if (p=='*')return x*y;
    if (p=='/')return x/y;
    if (p=='^')return pow(x,y);
}
int main()
{
    cin >>a;
    for (int i=0;i<strlen(a);i++)
    {
        if (a[i]>='0'&&a[i]<='9')b[n++]=a[i];
        else if (a[i]=='(')z[top++]=a[i];
        else if (a[i]==')')
        {
            while (z[top-1]!='(')b[n++]=z[--top];
            --top;
        }
        else {while(top&&cz(z[top-1],a[i]))b[n++]=z[--top];z[top++]=a[i];}
        /*cout <<i<<endl;
        for (int j=0;j<top;j++)cout <<z[j]<<' ';cout <<endl;
        for (int j=0;j<n;j++)cout <<a[j]<<' ';cout <<endl;*/
    }
    while (top){b[n++]=z[--top];}
    for (int i=0;i<n;i++)cout <<b[i]<<' ';cout <<endl;
    for (int i=0;i<n;i++)
    {
        if (b[i]>='0'&&b[i]<='9'){c[m++]=b[i]-'0';continue;}
        c[m-2]=js(c[m-2],c[m-1],b[i]);
        --m;
        for (int j=0;j<m;j++)cout <<c[j]<<' ';//cout <<"   ";
        for (int j=i+1;j<n;j++)cout <<b[j]<<' ';
        cout <<endl;
    }
    return 0;
}

