#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
const int MAXN = 105;
const int INF = 987654321;
const int popSize = 200;
const int maxGen = 500;
const int pLive = 50;
const int pMul = 3;
const int py = 1000000;

struct Unit
{
    int weight;
    int fitness;
    bool gene[MAXN];
};

struct Group
{
    int n, m, w[MAXN], c[MAXN];
    Unit unit[popSize + 5];
    int bestFit;
    int totalFit;
    double averFit;
    int gen;
    int newPop;
    
    void scan()
    {
        int a, b;
        cin >> a >> b;
        a += py; b += py;
        n = m = 2;
        w[0] = w[1] = 1;
        c[0] = a; c[1] = b;
    }
    
    int calc(Unit &t)
    {
        t.weight = t.fitness = 0;
        for (int i = 0; i < n; i++)
            if (t.gene[i])
            {
                t.weight += w[i];
                t.fitness += c[i];
            }
    }
    
    void init()
    {
        newPop = popSize * pLive / 100;
        for (int i = 0; i < popSize; i++)
        {
            unit[i].weight = unit[i].fitness = 0;
            memset(unit[i].gene, 0, sizeof(unit[i].gene));
            bool p[MAXN + 5] = {0};
            int fail = 0;
            while (fail < n)
            {
                int t = rand() % n;
                if (!p[t])
                {
                    p[t] = true;
                    fail++;
                    if (unit[i].weight + w[t] <= m)
                    {
                        unit[i].weight += w[t];
                        unit[i].fitness += c[t];
                        unit[i].gene[t] = true;
                    }
                }
            }
        }
    }
    
    void assess()
    {
        bestFit = 0;
        totalFit = 0;
        for (int i = 0; i < popSize; i++)
        {
            calc(unit[i]);
            bestFit = max(bestFit, unit[i].fitness);
            totalFit += unit[i].fitness;
        }
        averFit = totalFit * 1.0 / popSize;
    }
    
    void choose_sort()
    {
        for (int i = 0; i < popSize; i++)
            for (int j = i + 1; j < popSize; j++)
                if (unit[i].fitness < unit[j].fitness)
                    swap(unit[i], unit[j]);
    }
    
    void choose_jbs()
    {
        Unit tUnit[popSize + 5];
        memcpy(tUnit, unit, sizeof(tUnit));
        for (int i = 1; i < newPop; i++)
        {
            int t1 = rand() % popSize, t2 = rand() % popSize;
            if (tUnit[t1].fitness > tUnit[t2].fitness)
                unit[i] = tUnit[t1];
            else unit[i] = tUnit[t2];
        }
        for (int i = 1; i < popSize; i++)
            if (unit[i].fitness > unit[0].fitness)
                swap(unit[0], unit[i]);
    }
    
    void cross(const Unit &father, const Unit &mother, Unit &son)
    {
        bool ok = false;
        while (!ok)
        {
            int l = rand() % n, r = rand() % n;
            if (l > r)swap(l, r);
            son = father;
            for (int i = l; i <= r; i++)
                son.gene[i] = mother.gene[i];
            calc(son);
            if (son.weight <= m)
                ok = true;
        }
    }
    
    void cross1(const Unit &father, const Unit &mother, Unit &son)
    {
        bool ok = false;
        while (!ok)
        {
            for (int i = 0; i < n; i++)
                if (father.gene[i] == mother.gene[i])
                    son.gene[i] = father.gene[i];
                else son.gene[i] = rand() % 2;
            calc(son);
            if (son.weight <= m)
                ok = true;
        }
    }
    
    void mulate(Unit &t)
    {
        Unit tt;
        do
        {
            tt = t;
            for (int i = 0; i < n; i++)
                if (rand() % 100 < pMul)
                    tt.gene[i] = !tt.gene[i];
            calc(tt);
        }while (tt.weight > m);
        t = tt;
    }
    
    void print()
    {
        cout << bestFit - 2 * py << endl;
    }
    
    void print_gene()
    {
        for (int i = 0; i < popSize; i++)
        {
            printf("Num=%d, fitness=%d, weight=%d\n", i, unit[i].fitness, unit[i].weight);
            for (int j = 0; j < n; j++)cout << unit[i].gene[j] << ' ';
            cout << endl << endl; 
        }
    }
    
    void print_now()
    {
        printf("gen=%d\nbestFit=%d, averFit=%.2lf\n\n\n\n", gen, bestFit, averFit);
    }
    
    void evolution()
    {
        init();
        //print_gene();
        //system ("pause");
        for (gen = 1; gen <= maxGen; gen++)
        {
            assess();
            //print_gene(); 
            //if (gen % 10)print_now(); 
            //system ("pause");
            //choose_sort();
            choose_jbs();
            for (int i = newPop; i < popSize; i++)
            {
                int father = rand() % newPop, mother = rand() % newPop;
                cross(unit[father], unit[mother], unit[i]);
            }
            for (int i = 1; i < popSize; i++)
                mulate(unit[i]);
        }
    }
};

int main()
{
    Group g;
    g.scan();
    g.evolution();
    g.print();
    return 0;
}
