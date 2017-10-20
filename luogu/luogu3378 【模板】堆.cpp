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

template<class T> class MinHeap
{
private:
    T *heap;
    int cap;
    int size;
public:
    MinHeap(int capacity = 100000);
    ~MinHeap(){delete[] heap;}
    bool push(T data);
    bool pop();
    T getTop();
    int getSize();
    bool empty();
}; 

template<class T> MinHeap<T>::MinHeap(int _cap)
{
    cap = _cap;
    size = 0;
    heap = new T[cap];
}

template<class T> bool MinHeap<T>::push(T val)
{
    if (size == cap)
        return false;
    int cur = size++;
    while (cur > 0)
    {
        int parent = (cur - 1) / 2;
        if (val >= heap[parent])
            break;
        heap[cur] = heap[parent];
        cur = parent;
    }
    heap[cur] = val;
    return true;
}

template<class T> bool MinHeap<T>::pop()
{
    if (!size)
        return false;
    T val = heap[--size];
    int cur = 0, son;
    while ((son = cur * 2 + 1) < size)
    {
        if (son + 1 < size && heap[son+1] < heap[son])
            ++son;
        if (val <= heap[son])
            break;
        heap[cur] = heap[son];
        cur = son;
    }
    heap[cur] = val;
    return true;
}

template<class T> T MinHeap<T>::getTop()
{
    if (size)
        return heap[0];
}

template<class T> int MinHeap<T>::getSize()
{
    return size;
}

template<class T> bool MinHeap<T>::empty()
{
    return !size;
}

int main()
{
    MinHeap<int> heap(1000000);
    int n, p, x;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &p);
        if (p == 1)
            heap.push((scanf("%d", &x), x));
        else if (p == 2)
            printf("%d\n", heap.getTop());
        else
            heap.pop();
    }
    return 0;
}

