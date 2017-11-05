#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=100000+2017;
void Read(int & p)
{
    p=0;
    int f=1;
    char c=getchar();
    while(c<'0' or c>'9') 
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c<='9' and c>='0')
        p=p*10+c-'0',c=getchar();
    p*=f;
    return ;
}
int n,ask,fri;
vector <int> Epic;
int main()
{
    Read(n);
    for(int i=1;i<=n;i++)
    {
        Read(ask); Read(fri);
        if(ask==1)//insert���ں��ʵ�λ�ò���һ��ֵ
            Epic.insert(upper_bound(Epic.begin(),Epic.end(),fri),fri);//upper_bound(a,b,c)������[a,b]�е�һ�����ڵ���c��ֵ���±�
        else if(ask==2)//erase����ȥ���ֵ
            Epic.erase(lower_bound(Epic.begin(),Epic.end(),fri));
        else if(ask==3)//���һ�����ڵ��������±꣨Ҳ����������
            printf("%d\n",lower_bound(Epic.begin(),Epic.end(),fri)-Epic.begin()+1);
        else if(ask==4)//���������Ӧ��ֵ
            printf("%d\n",Epic[fri-1]);
        else if(ask==5)//��ǰ���ͺ�̣�ע��*�����ص���ֵ
            printf("%d\n",*--lower_bound(Epic.begin(),Epic.end(),fri));
        else printf("%d\n",*upper_bound(Epic.begin(),Epic.end(),fri));
    }
    return 0;
}
