#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
    string s;
    char zm;
    int sz=0,fh=1,dh=1,t=0,xs=0;
    cin >>s;
    for (int i=0;i<s.size();i++)
      if (s[i]=='+')
      {
            t-=sz*fh*dh;
            sz=0;fh=1;
      }
      else if (s[i]=='-')
      {
            t-=sz*fh*dh;
            sz=0;fh=-1;
      }
      else if (s[i]=='=')
      {
            t-=sz*fh*dh;
            sz=0;fh=1;dh=-1;
      }
      else if (s[i]>='a'&&s[i]<='z')
      {
            if (!sz)sz=1;
            xs+=sz*fh*dh;
            sz=0;zm=s[i];
      }
      else sz=sz*10+s[i]-'0';
    t-=sz*fh*dh;
    //cout <<t<<' '<<xs<<endl;
    if (t==0||xs==0)cout <<zm<<"=0.000"; 
    else printf ("%c=%.3f",zm,t*1.0/xs);
}
