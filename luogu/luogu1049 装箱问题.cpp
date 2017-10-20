#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
const int MAXN = 35;
const int INF = 987654321;
const int popSize = 100;
const int maxGen = 300;
const int pLive = 60;
const int pMul = 8;

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
        cin >> m >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
            c[i] = w[i];
        }
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
    
    void mulate(Unit &t)
    {
        Unit tt;
        Unit ttt;
        for (int i = 0; i < n / 3; i++)
        {
            do
            {
                tt = t;
                for (int i = 0; i < n; i++)
                    if (rand() % 100 < pMul)
                        tt.gene[i] = -tt.gene[i];
                calc(tt);
            }while (tt.weight > m);
            if (tt.fitness <= t.fitness)
            {
                t = tt;
                return;
            }
            if (!ttt.fitness || tt.fitness < ttt.fitness)
                ttt = tt;
        }
        t = ttt;
    }
    
    void print_ans()
    {
        cout << m - bestFit << endl;
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
        printf("gen=%d\nbestFit=%d, averFit=%.2lf\nbestGene: ", gen, bestFit, averFit);
        for (int i = 0; i < n; i++)cout << unit[0].gene[i] << ' ';
        cout << endl << endl;
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
            //print_now(); 
            //system ("pause");
            choose_sort();
            for (int i = newPop; i < popSize; i++)
            {
                int father = rand() % newPop, mother = rand() % newPop;
                cross(unit[father], unit[mother], unit[i]);
            }
            for (int i = 1; i < popSize; i++)
                mulate(unit[i]);
        }
        print_ans();
    }
};

int main()
{
    Group g;
    g.scan();
    g.evolution();
    return 0;
}
