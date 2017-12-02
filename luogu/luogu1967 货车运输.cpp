#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN1=10001;//���� 
const int MAXN2=50001;//���� 
struct edge
{
    int v,len;
    edge(int vv=0,int ll=0) {v=vv;len=ll;}
};//����ʱ����� 
struct BIAN
{
    int Left,Right,length;
}bian[MAXN2];//�ʼ����ı� 
vector<edge> G[MAXN1];//������� 
int n,m,q,u,v;
int fa[MAXN1],size[MAXN1];//���鼯�������������ʱ�ã� 
int lg[MAXN1],depth[MAXN2];//Ԥ����log����Ƚ����Ӱ�죩 �Լ�ÿһ�������� 
int father[20][MAXN1],flen[20][MAXN1];//������lca ͬʱά��ÿ���㵽�����ȵı�Ȩ����Сֵ 
inline int getfa(int x)//���鼯 ������ 
{
    if(fa[x]==x) return x;
    else return fa[x]=getfa(fa[x]);
}
inline void Merge(int x,int y)//���鼯 �ϲ�������ʽ�� 
{
    int nx=getfa(x),ny=getfa(y);
    if(size[nx]<size[ny]) swap(nx,ny);
    fa[ny]=nx;size[nx]+=size[ny];
}
inline void gettree(int nowroot,int dad,int deep)
{  //���� ����nowrootΪ���ڵ㣬nowroot�ĸ�����dad��nowroot�������deep  �����ϵ��޸���ת�и��� 
    int s=G[nowroot].size();
    depth[nowroot]=deep;
    for(int i=0;i<s;++i)    //������ǰ���ĳ��� 
    {
        int nv=G[nowroot][i].v,nl=G[nowroot][i].len;
        if(nv!=dad)    //�ݹ���ֹ�����ж� 
        {
            father[0][nv]=nowroot;    //ÿ���㸸�ڵ�Ĵ��� 
            flen[0][nv]=nl;    //˳�㴦�����С��Ȩ 
            gettree(nv,nowroot,deep+1);      //ת��Ϊ��nvΪ���ڵ�������Ĺ��� 
        }
    }
}
inline void getready()//������Ԥ���� 
{
    lg[1]=0;
    for(int i=2;i<=n;++i)
        lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);        //log��Ԥ���� 
    gettree(1,0,0);                                //���� 
    for(int i=1;i<=lg[n];++i)                  //�����Ĵ��� 
        for(int j=1;j<=n;++j)
        {
            father[i][j]=father[i-1][father[i-1][j]];
            flen[i][j]=min(flen[i-1][j],flen[i-1][father[i-1][j]]);
        }
}
inline int lca(int x,int y)//��lca 
{
    int xans=2147483647,yans=2147483647;
    if(depth[x]<depth[y]) swap(x,y);        //ʹ��x�����һ����y����ȸ��� 
    while(depth[x]>depth[y])
    {
        xans=min(xans,flen[lg[depth[x]-depth[y]]][x]);
        x=father[lg[depth[x]-depth[y]]][x];
    }                                        //x��y����ͬһ�߶� 
    if(x==y) return xans;                    //������һ�� 
    for(int k=lg[depth[x]];k>=0;--k)                //һ�������� 
    {
        //if(flen[k][x]!=0) xans=min(xans,flen[k][x]);
        //if(flen[k][y]!=0) yans=min(yans,flen[k][y]);
        if(father[k][x]!=father[k][y])
        {
            xans=min(xans,flen[k][x]);;x=father[k][x];
            yans=min(yans,flen[k][y]);;y=father[k][y];
        }
    }
    return min(min(xans,yans),min(flen[0][x],flen[0][y]));
}
inline bool CMP(const BIAN &a,const BIAN &b)//������ 
{
    return a.length>b.length;
}
inline int read()//�����Ż� 
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
    return x;
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=m;++i)
        {bian[i].Left=read();bian[i].Right=read();bian[i].length=read();}  //���� ���� �Լ�ÿһ���ߵ����� 
    sort(bian+1,bian+m+1,CMP);                    //�Ա߰��������� 
    for(int i=1;i<=n;++i) {fa[i]=i;size[i]=1;}    //���鼯Ԥ���� 
    for(int i=1;i<m;++i)        //102~111�� ��������� 
    {
        int nl=bian[i].Left,nr=bian[i].Right;
        if(getfa(nl)!=getfa(nr))
        {
            Merge(nl,nr);
            G[nl].push_back(edge(nr,bian[i].length));    //ͬʱΪ������׼�� 
            G[nr].push_back(edge(nl,bian[i].length));
        }
    }
    getready();    //Ԥ���� 
    q=read(); 
    for(int w=0;w<q;++w)
    {
        u=read();v=read();
        if(getfa(u)!=getfa(v)) printf("-1\n");    //������һ���ܲ��ܵ��� 
        else printf("%d\n",lca(u,v));//�ҵ�lca����С�ı�Ȩ 
    }
    return 0;
}
