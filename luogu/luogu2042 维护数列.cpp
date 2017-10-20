#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
using namespace std;
const int MAXN = 500050;
const int INF = 0x3f3f3f3f;

struct Node
{
    Node *fa, *c[2];
    int val, maxl, maxr, maxm, sum, size;
    bool same, rev;
}node[MAXN];

typedef Node* PNODE;

PNODE pool[MAXN], null, head, tail, root;
int poolTop = MAXN;

void hello(){cout << "hello, " << rand() % 100 << endl;}
void zxbl(PNODE x)
{
    if (x->c[0] != null)
        zxbl(x->c[0]);
    cout << x->val << ' ';
    if (x->c[1] != null)
        zxbl(x->c[1]);
}
void xxbl(PNODE x)
{
    printf("%d %d %d %d %d %d %d %d\n", x->val, x->same, x->maxl, x->maxr, x->maxm, x->size, x->c[0]!=null, x->c[1]!=null);
    if (x->c[0] != null) xxbl(x->c[0]);
    if (x->c[1] != null) xxbl(x->c[1]);
}

void init();
PNODE newNode(PNODE, int, bool);
bool getlr(PNODE);
void setc(PNODE, bool, PNODE);
PNODE build(int, int);
void update(PNODE);
void putSame(PNODE, int);
void putRev(PNODE);
void pushdown(PNODE);
void rotate(PNODE);
void splay(PNODE);
void find(PNODE, int);
PNODE split(int, int);
void upRoot();
void insert(int, int);
void erase(int, int);
void makeSame(int, int, int);
void reverse(int, int);
int getSum(int, int);
int maxSum(PNODE);

void init()
{
    null = &node[--poolTop];
    null->fa = null->c[0] = null->c[1] = null;
    null->size = null->sum = 0;
    null->val = null->maxl = null->maxr = null->maxm = -INF;
    null->same = null->rev = false;
    for (int i = 0; i < poolTop; i++)
        pool[i] = &node[i], pool[i]->c[0] = pool[i]->c[1] = null;
}

PNODE newNode(PNODE fa, int lr, int val)
{
    if (!poolTop){ cout << "MLE!!!\n"; return null; }
    PNODE x = pool[--poolTop];
    if (x->c[0] != null) pool[poolTop++] = x->c[0], x->c[0] = null;
    if (x->c[1] != null) pool[poolTop++] = x->c[1], x->c[1] = null;
    x->fa = fa; if (fa != null) fa->c[lr] = x;
    x->val = x->maxl = x->maxr = x->maxm = x->sum = val;
    x->size = 1; x->same = x->rev = false;
    return x;
}

inline bool getlr(PNODE x)
{
    if (x == null || x->fa == null) { cout << "Try to get the son of null!\n"; return 0; }
    return x == x->fa->c[1];
}

inline void setc(PNODE father, bool lr, PNODE child)
{
    child->fa = father;
    if (father != null) father->c[lr] = child;
}

void update(PNODE x)
{
    if (x == null) return;
    PNODE lc = x->c[0], rc = x->c[1];
    x->size = lc->size + rc->size + 1;
    x->sum = lc->sum + rc->sum + x->val;
    x->maxl = max(lc->maxl, lc->sum + x->val + max(0, rc->maxl));
    x->maxr = max(rc->maxr, rc->sum + x->val + max(0, lc->maxr));
    x->maxm = max(max(lc->maxm, rc->maxm), max(lc->maxr, 0) + x->val + max(rc->maxl, 0));
}

PNODE build(int l, int r)
{
    if (l > r) return null;
    int mid = (l + r) >> 1, val;
    PNODE lc = build(l, mid-1), x;
    x = newNode(null, 0, (scanf("%d", &val), val));
    setc(x, 0, lc);
    setc(x, 1, build(mid+1, r));
    return update(x), x;
}

void putSame(PNODE x, int val)
{
    if (x == null) return;
    x->same = true;
    x->val = val;
    x->sum = val * x->size;
    x->maxl = x->maxr = x->maxm = max(x->sum, val);
    x->rev = false;
}

void putRev(PNODE x)
{
    if (x == null) return;
    x->rev ^= 1;
    swap(x->c[0], x->c[1]);
    swap(x->maxl, x->maxr);
}

void pushdown(PNODE x)
{
    if (x == null) return;
    if (x->same) x->same = false, putSame(x->c[0], x->val), putSame(x->c[1], x->val);
    if (x->rev) x->rev = false, putRev(x->c[0]), putRev(x->c[1]);
}

void rotate(PNODE x)
{
    PNODE y = x->fa, z = y->fa;
    bool lr = !getlr(x);
    x->fa = z; if (z != null) z->c[getlr(y)] = x;
    if (x->c[lr] != null) setc(y, !lr, x->c[lr]); else y->c[!lr] = null;
    setc(x, lr, (update(y), y));
}

void splay(PNODE x, PNODE tofa)
{
    for (pushdown(x); x->fa != tofa; rotate(x))
        if (x->fa->fa != tofa)
            rotate(getlr(x) ^ getlr(x->fa) ? x : x->fa);
    if (tofa == null) root = x;
    update(x);
}

void find(PNODE to, int kth)
{
    PNODE x = (pushdown(to), to);
    for (int size; kth != (size = x->c[0]->size); pushdown(x))
        if (kth < size) x = x->c[0];
        else kth -= size + 1, x = x->c[1];
    splay(x, to->fa);
}

inline PNODE split(int pos, int tot)
{
    find(root, pos-1);
    find(root->c[1], tot);
    return root->c[1]->c[0];
}

inline void upRoot(){ update(root->c[1]), update(root); }

inline void insert(int pos, int tot)
{
    find(root, pos);
    find(root->c[1], 0);
    setc(root->c[1], 0, build(1, tot));
    upRoot();
}

inline void erase(int pos, int tot)
{
    PNODE x = split(pos, tot)->fa;
    pool[poolTop++] = x->c[0];
    x->c[0] = null;
    upRoot();
}

inline void makeSame(int pos, int tot, int num)
{
    putSame(split(pos, tot), num);
    upRoot();
}

inline void reverse(int pos, int tot)
{
    putRev(split(pos, tot));
    upRoot();
}

inline int getSum(int pos, int tot){ return split(pos, tot)->sum; }

inline int maxSum(PNODE x){ return x->maxm; }

int main()
{
    init();
    int n, q;
    scanf("%d%d", &n, &q);
    head = newNode(null, 0, -INF);
    tail = newNode(head, 1, -INF);
    head->sum = tail->sum = 0;
    setc(tail, 0, build(1, n));
    update(tail), update(head);
    root = head;
    char sr[30], op;
    int pos, tot, num;
    while (q--)
    {
        //xxbl(root);
        scanf("%s", sr);
        op = sr[2];
        if (op == 'X')
        {
            printf("%d\n", maxSum(root));
            continue;
        }
        scanf("%d%d", &pos, &tot);
        switch (op)
        {
            case 'S': insert(pos, tot); break;
            case 'L': erase(pos, tot); break;
            case 'K': makeSame(pos, tot, (scanf("%d", &num), num)); break;
            case 'V': reverse(pos, tot); break;
            case 'T': printf("%d\n", getSum(pos, tot)); break;
        }
    }
    return 0;
}

