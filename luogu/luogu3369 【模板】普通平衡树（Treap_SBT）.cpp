#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f, MAXN = 100050;
struct Node
{
    int fa, ch[2], size, num, cnt;
    Node(){fa = ch[0] = ch[1] = size = num = cnt = 0;}
}node[MAXN];
int top = 1;  // nodeĩβ 
int root;  // ���� 

int newNode(int num)  // ����ֵΪnum���½ڵ� 
{
    node[top].num = num;
    node[top].cnt = node[top].size = 1;
    return top++;
}

bool getlr(int x)  // ����x�Ǹ��׵��ĸ����� 
{
    return node[node[x].fa].ch[1] == x;
}

void connect(int f, bool lr, int c)  // ��f��lr������Ϊc 
{
    if (f) node[f].ch[lr] = c;
    if (c) node[c].fa = f;
}

void update(int x)  // ����x�ڵ��¼����Ϣ 
{
    node[x].size = node[x].cnt + node[node[x].ch[0]].size + node[node[x].ch[1]].size;
}

void rotate(int x)  // ��תx 
{
    bool lr = !getlr(x);  // 0����1����
    int y = node[x].fa, z = node[y].fa;
    connect(z, getlr(y), x);
    connect(y, !lr, node[x].ch[lr]);
    connect(x, lr, y);
    update(y);
}

void splay(int x, int tofa)  // ��x��ת��tofa�Ķ���λ�� 
{
    for (; node[x].fa != tofa; rotate(x))
        if (node[node[x].fa].fa != tofa)
            rotate(getlr(x) ^ getlr(node[x].fa) ? x : node[x].fa);
    if (!tofa) root = x; 
    update(x);
}

void insert(int num)  // ������num 
{
    int x = root, y = 0;
    while (x && node[x].num != num)
        y = x, x = node[x].ch[num>node[x].num];
    if (x) ++node[x].cnt;
    else connect(y, num>node[y].num, (x = newNode(num)));
    splay(x, 0);
}

void find(int num)  // ������num���ڽڵ㲢�ᵽ�� 
{
    int x = root;
    while (node[x].num != num && node[x].ch[node[x].num<num])
        x = node[x].ch[node[x].num<num];
    splay(x, 0);
}

int kth(int k)  // ��ѯ��k����� 
{
    ++k;
    int x = root;
    while (x)
    {
        int lsize = node[node[x].ch[0]].size;
        if (k > lsize && k <= lsize + node[x].cnt)
        {
            splay(x, 0);
            return node[root].num;
        }
        if (k <= lsize) x = node[x].ch[0];
        else k -= lsize + node[x].cnt, x = node[x].ch[1];
    }
    return -1;
} 

int rk(int num)  // ��ѯ��num������ 
{
    find(num);
    return node[node[root].ch[0]].size;
}

int nop(int num, bool np)  // np=0��ǰ����1�Һ�̣�����Ŀ��ڵ��� 
{
    find(num);
    if (node[root].num != num && (node[root].num > num) == np)
        return root;
    int x = node[root].ch[np];
    while (node[x].ch[!np])
        x = node[x].ch[!np];
    return x;
}

int nextOrPre(int num, bool np)  // np=0��ǰ����1�Һ�̣�����Ŀ��ڵ����� 
{
    splay(nop(num, np), 0);
    return node[root].num;
}

void del(int num)  // ɾ��num�����ж��ֻɾһ���� 
{
    int pre = nop(num, 0), next = nop(num, 1);
    splay(pre, 0), splay(next, pre);
    int x = node[next].ch[0];
    if (--node[x].cnt) splay(x, 0);
    else connect(next, 0, 0), splay(next, 0);
} 

int main()
{
    int m;
    scanf("%d", &m);
    insert(-INF), insert(INF);
    while (m--)
    {
        int opt, x;
        scanf("%d%d", &opt, &x);
        switch (opt)
        {
            case 1: insert(x); break;
            case 2: del(x); break;
            case 3: printf("%d\n", rk(x)); break;
            case 4: printf("%d\n", kth(x)); break;
            case 5: printf("%d\n", nextOrPre(x, 0)); break;
            case 6: printf("%d\n", nextOrPre(x, 1)); break;
        }
    }
    return 0;
}
