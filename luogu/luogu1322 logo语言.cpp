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
int rp(string s)  
{  
    int w=s.size(),as=0,t,b1=0,b2=0,t1=0,j;  
    for (int i=0;i<w;i++)  
    {  
        if (s[i+1]>='0'&&s[i+1]<='9')  
        {  
            t=0;j=i+1;  
            while (s[j]>='0'&&s[j]<='9')  
            {t=t*10+(s[j]-'0');++j;}  
            if (s[i]=='d')  
              as+=t;  
            else if (s[i]=='k')  
              as-=t;  
            else if (s[i]=='t')  
            {  
                for (int k=i;;k++)  
                  if (s[k]=='[')  
                  {  
                      if (!b1)  
                        b1=k;  
                      ++t1;  
                  }  
                  else if (s[k]==']')  
                  {  
                      if (!--t1)  
                      {  
                          b2=k;  
                          break;  
                      }  
                  }  
                as+=t*rp(s.substr(b1+1,b2-b1-1));  
                i=b2;  
                b1=b2=t1=0;  
            }  
        }  
    }  
    return as;  
}  
int main()
{
    string a;
    getline(cin,a);
    for (int i=0;i<a.size();i++)
    {
       if (a[i]==' ')
       {a.erase(i,1);--i;}
       else if (a[i]>='A'&&a[i]<='Z')
         a[i]+=32;
    }
    cout <<abs(rp(a));
    return 0;
}
