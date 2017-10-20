#include<iostream>     
#include<cstdio>     
#include<string>     
#include<algorithm>     
using namespace std;     
int c=0,p[6]={0},sum=0;     
void cha(string &s)     
{
     if(s=="one"||s=="a"||s=="first"||s=="another"){p[c]=1;c++;}     
     if(s=="two"||s=="both"||s=="second"){p[c]=4;c++;}     
     if(s=="three"||s=="third"){p[c]=9;c++;}     
     if(s=="four"){p[c]=16;c++;}     
     if(s=="five"){p[c]=25;c++;}     
     if(s=="six"){p[c]=36;c++;}     
     if(s=="seven"){p[c]=49;c++;}     
     if(s=="eight"){p[c]=64;c++;}     
     if(s=="nine"){p[c]=81;c++;}     
     if(s=="eleven"){p[c]=21;c++;}     
     if(s=="twelve"){p[c]=44;c++;}     
     if(s=="thirteen"){p[c]=69;c++;}     
     if(s=="fourteen"){p[c]=96;c++;}     
     if(s=="fifteen"){p[c]=25;c++;}     
     if(s=="sixteen"){p[c]=56;c++;}     
     if(s=="seventeen"){p[c]=89;c++;}     
     if(s=="eighteen"){p[c]=24;c++;}     
     if(s=="nineteen"){p[c]=61;c++;}     
}     
int main()
{
    string s[6];
    for(int s1=0;s1<6;s1++)cin>>s[s1];
    for(int s1=0;s1<6;s1++)cha(s[s1]);
    sort(p,p+c);
    for(int i=0;i<c;i++)       
    {       
        sum=(sum+p[i])*100;
    }       
    cout<<sum/100;    return 0;     
}   
