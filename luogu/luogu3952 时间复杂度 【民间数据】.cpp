#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int i,j,k,m,n,s,t;
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
int h[30],n1,ss,s1,s2,st,sta[101000],now,tmp,a[101000],b[101000],c[101000],ans1,ans;
char ch[101000];
int main()
{
	int T=read();
	while (T--)
	{
		n=0;
		m=read();
		scanf("%s",ch);
		n1=strlen(ch);
		memset(h,0,sizeof(h));
		if (n1==4) ans1=0; else if (n1==6) ans1=ch[4]-'0'; else ans1=(ch[4]-'0')*10+ch[5]-'0';
		//printf("%d %d\n",n1,ans1);
		ans=0;
		st=0;
		tmp=0;
		now=0;
		for (;m;)
		{
			m--;
			scanf("%s",ch);
			if (ch[0]=='F')
			{
				++n;
				sta[++st]=n;
				scanf("%s",ch);
				a[n]=ch[0]-'a'+1;
				scanf("%s",ch);
				ss=strlen(ch);
				if (ch[0]=='n') s1=101; else if (ss==2) s1=(ch[0]-'0')*10+ch[1]-'0'; else s1=ch[0]-'0';
				scanf("%s",ch);
				ss=strlen(ch);
				if (ch[0]=='n') s2=101; else if (ss==2) s2=(ch[0]-'0')*10+ch[1]-'0'; else s2=ch[0]-'0';
				if (s1>s2) c[n]=1; else c[n]=0;
				tmp+=c[n];
				if (s2==101&&s1<101) b[n]=1; else b[n]=0;
				if (tmp) b[n]=0;
				now+=b[n];
				if (h[a[n]]) {ans=-1; break;}
				h[a[n]]=1;
				ans=max(ans,now);
				//printf("%d\n",now); ///!!!!!!!!!!
			} else
			{
				if (st<1) {ans=-1;break;}
				now-=b[sta[st]];
				tmp-=c[sta[st]];
				h[a[sta[st]]]=0;
				st--;
			}
		}
		if (st) ans=-1;
		//printf("%d %d\n",ans,ans1);  ///!!!!!!!!!!!
		for (;m;)
		{
			m--;
			scanf("%s",ch);
			if (ch[0]=='E')
			{
				s=0;
			} else
			{
				scanf("%s",ch);
				scanf("%s",ch);
				scanf("%s",ch);
			}
		}
		if (ans==-1) puts("ERR"); else if (ans==ans1) puts("Yes"); else puts("No");
	}
}

