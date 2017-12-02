#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN1=10001;//点数 
const int MAXN2=50001;//边数 
struct edge
{
    int v,len;
    edge(int vv=0,int ll=0) {v=vv;len=ll;}
};//建树时存边用 
struct BIAN
{
    int Left,Right,length;
}bian[MAXN2];//最开始输入的边 
vector<edge> G[MAXN1];//建树存边 
int n,m,q,u,v;
int fa[MAXN1],size[MAXN1];//并查集（找最大生成树时用） 
int lg[MAXN1],depth[MAXN2];//预处理log（洛谷讲义的影响） 以及每一个点的深度 
int father[20][MAXN1],flen[20][MAXN1];//倍增找lca 同时维护每个点到他祖先的边权的最小值 
inline int getfa(int x)//并查集 找祖先 
{
    if(fa[x]==x) return x;
    else return fa[x]=getfa(fa[x]);
}
inline void Merge(int x,int y)//并查集 合并（启发式） 
{
    int nx=getfa(x),ny=getfa(y);
    if(size[nx]<size[ny]) swap(nx,ny);
    fa[ny]=nx;size[nx]+=size[ny];
}
inline void gettree(int nowroot,int dad,int deep)
{  //建树 （以nowroot为根节点，nowroot的父亲是dad，nowroot的深度是deep  紫书上的无根树转有根树 
    int s=G[nowroot].size();
    depth[nowroot]=deep;
    for(int i=0;i<s;++i)    //遍历当前结点的出边 
    {
        int nv=G[nowroot][i].v,nl=G[nowroot][i].len;
        if(nv!=dad)    //递归终止条件判断 
        {
            father[0][nv]=nowroot;    //每个点父节点的处理 
            flen[0][nv]=nl;    //顺便处理掉最小边权 
            gettree(nv,nowroot,deep+1);      //转化为以nv为根节点的子树的构建 
        }
    }
}
inline void getready()//倍增的预处理 
{
    lg[1]=0;
    for(int i=2;i<=n;++i)
        lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);        //log的预处理 
    gettree(1,0,0);                                //建树 
    for(int i=1;i<=lg[n];++i)                  //倍增的处理 
        for(int j=1;j<=n;++j)
        {
            father[i][j]=father[i-1][father[i-1][j]];
            flen[i][j]=min(flen[i-1][j],flen[i-1][father[i-1][j]]);
        }
}
inline int lca(int x,int y)//找lca 
{
    int xans=2147483647,yans=2147483647;
    if(depth[x]<depth[y]) swap(x,y);        //使得x的深度一定比y的深度更大 
    while(depth[x]>depth[y])
    {
        xans=min(xans,flen[lg[depth[x]-depth[y]]][x]);
        x=father[lg[depth[x]-depth[y]]][x];
    }                                        //x与y跳到同一高度 
    if(x==y) return xans;                    //先特判一下 
    for(int k=lg[depth[x]];k>=0;--k)                //一起向上跳 
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
inline bool CMP(const BIAN &a,const BIAN &b)//排序函数 
{
    return a.length>b.length;
}
inline int read()//输入优化 
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
        {bian[i].Left=read();bian[i].Right=read();bian[i].length=read();}  //点数 边数 以及每一条边的输入 
    sort(bian+1,bian+m+1,CMP);                    //对边按长度排序 
    for(int i=1;i<=n;++i) {fa[i]=i;size[i]=1;}    //并查集预处理 
    for(int i=1;i<m;++i)        //102~111行 最大生成树 
    {
        int nl=bian[i].Left,nr=bian[i].Right;
        if(getfa(nl)!=getfa(nr))
        {
            Merge(nl,nr);
            G[nl].push_back(edge(nr,bian[i].length));    //同时为建树做准备 
            G[nr].push_back(edge(nl,bian[i].length));
        }
    }
    getready();    //预处理 
    q=read(); 
    for(int w=0;w<q;++w)
    {
        u=read();v=read();
        if(getfa(u)!=getfa(v)) printf("-1\n");    //先特判一下能不能到达 
        else printf("%d\n",lca(u,v));//找到lca求最小的边权 
    }
    return 0;
}
