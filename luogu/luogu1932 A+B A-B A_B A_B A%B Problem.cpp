#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

class Bigint  //大整数类数组实现 
{
private:
    static const int MAXL = 20050;  //数的最大位数 
    int len;  //数的位数 
    int s[MAXL];  //正序保存每一位数字 
    bool sign;  //0为负1为正

public:
    Bigint();
    Bigint(const char*);
    Bigint(string);
    Bigint(int);  //构造函数
    
    void print() const;  //打印类信息用于调试 
    
    void clean();  //去掉前导0及处理-0的情况 
    
    operator string() const;  //转换为string类型
    
    friend istream& operator>>(istream&, Bigint&);  //重载输入流 
    friend ostream& operator<<(ostream&, const Bigint&);  //重载输出流
    
    Bigint& operator=(const char*);
    Bigint& operator=(string);
    Bigint& operator=(int);  //重载赋值函数 
    
    friend bool operator>(const Bigint&, const Bigint&);
    friend bool operator<(const Bigint&, const Bigint&);
    friend bool operator>=(const Bigint&, const Bigint&);
    friend bool operator<=(const Bigint&, const Bigint&);
    friend bool operator==(const Bigint&, const Bigint&);
    friend bool operator!=(const Bigint&, const Bigint&);  //重载比较
    
    Bigint operator-() const;  //取相反数
    friend Bigint abs(const Bigint &);  //取绝对值 
    
    friend Bigint operator+(const Bigint&, const Bigint&);
    Bigint operator+=(const Bigint&);
    Bigint operator++();
    Bigint operator++(int);  //重载加法 
    
    friend Bigint operator-(const Bigint&, const Bigint&);
    Bigint operator-=(const Bigint&);
    Bigint operator--();
    Bigint operator--(int);  //重载减法 
    
    friend Bigint operator*(const Bigint&, const Bigint&);
    Bigint operator*=(const Bigint&);  //重载乘法
    
    friend Bigint operator/(const Bigint&, const Bigint&);
    Bigint operator/=(const Bigint&);  //重载除法
    
    friend Bigint operator%(const Bigint&, const Bigint&);
    Bigint operator%=(const Bigint&);  //重载取余 
    
    friend Bigint factorial(const Bigint&);  //阶乘
    friend Bigint sqrt(const Bigint&);  //开平方根向下取整 
    friend Bigint pow(const Bigint&, const Bigint&);  //次方 
};

void Bigint::print() const
{
    cout << "-----Bigint print in-----\n";
    cout << len << ' ' << sign << ' ';
    for (int i = len - 1; i >= 0; i--)
        cout << s[i];
    cout << endl;
    cout << "-----Bigint print out-----\n";
}

Bigint::Bigint()
{
    memset(s, 0, sizeof(s));
    len = 1;
    sign = true;
}

Bigint::Bigint(const char *num)
{
    *this = num;
}

Bigint::Bigint(int num)
{
    *this = num;
}

void Bigint::clean()
{
    if (!len)++len;
    while (len > 1 && !s[len - 1])--len;
    if (len == 1 && !s[0])sign = true;
}

Bigint::operator string() const
{
    string ret = "";
    for (int i = len - 1; i >= 0; i--)
        ret += s[i] + '0';
    if (ret == "")ret = "0";
    if (!sign)ret = '-' + ret;
    return ret;
}

istream& operator>>(istream &in, Bigint &num)
{
    string r;
    in >> r;
    num = r;
    return in;
}

ostream& operator<<(ostream &out, const Bigint &num)
{
    out << string(num);
    return out;
}

Bigint& Bigint::operator=(const char *num)
{
    memset(s, 0, sizeof(s));
    char a[MAXL] = "";
    if (num[0] == '-')
        strncpy(a, num + 1, strlen(num) - 1);
    else strcpy(a, num);
    sign = (num[0] != '-');
    len = strlen(a);
    for (int i = 0; i < len; i++)
        s[i] = a[len - i - 1] - '0';
    this->clean();
    return *this;
}

Bigint& Bigint::operator=(string num)
{
    *this = num.c_str();
    this->clean();
    return *this;
}

Bigint& Bigint::operator=(int num)
{
    char a[MAXL];
    sprintf(a, "%d", num);
    *this = a;
    this->clean();
    return *this;
}

bool operator>(const Bigint &a, const Bigint &b)
{
    if (a.sign ^ b.sign)return a.sign;
    if (a.len != b.len)return a.len > b.len;
    for (int i = a.len - 1; i >= 0; i--)
        if (a.s[i] != b.s[i])
            return a.sign ^ (a.s[i] < b.s[i]);
    return false;
}

bool operator<(const Bigint &a, const Bigint &b)
{
    return b > a;
}

bool operator>=(const Bigint &a, const Bigint &b)
{
    return !(a < b);
}

bool operator<=(const Bigint &a, const Bigint &b)
{
    return !(a > b);
}

bool operator==(const Bigint &a, const Bigint &b)
{
    return !(a < b || a > b);
}

bool operator!=(const Bigint &a, const Bigint &b)
{
    return !(a == b);
}

Bigint Bigint::operator-() const
{
    if (len == 1 && s[0] == '0')return *this;
    Bigint ret = *this;
    ret.sign = !sign;
    return ret;
}

Bigint abs(const Bigint &num)
{
    if (!num.sign)return -num;
    return num;
}

Bigint operator+(const Bigint &a, const Bigint &b)
{
    if (a.sign ^ b.sign)
        return a.sign ? a - (-b) : b - (-a);
    Bigint ret;
    ret.len = 0;
    ret.sign = a.sign;
    int x = 0;
    for (int i = 0, x = 0; x || i < max(a.len, b.len); i++)
    {
        x += a.s[i] + b.s[i];
        ret.s[ret.len++] = x % 10;
        x /= 10;
    }
    ret.clean();
    return ret;
}

Bigint Bigint::operator+=(const Bigint &num)
{
    *this = *this + num;
    return *this;
}

Bigint Bigint::operator++()
{
    return *this += 1;
}

Bigint Bigint::operator++(int)
{
    Bigint t = *this;
    *this += 1;
    return t;
}

Bigint operator-(const Bigint &a, const Bigint &b)
{
    if (!a.sign && !b.sign)
        return (-b) - (-a);
    if (!a.sign)return b + (-a);
    if (!b.sign)return a + (-b);
    if (a < b)return -(b - a);
    Bigint ret;
    ret.len = 0;
    for (int i = 0, x = 0; i < a.len; i++)
    {
        int t = a.s[i] - x;
        if (i < b.len)t -= b.s[i];
        if (t < 0)
        {
            x = 1;
            t += 10;
        }
        else x = 0;
        ret.s[ret.len++] = t;
    }
    ret.clean();
    return ret;
}

Bigint Bigint::operator-=(const Bigint &num)
{
    *this = *this - num;
    return *this;
}

Bigint Bigint::operator--()
{
    return *this -= 1;
}

Bigint Bigint::operator--(int)
{
    Bigint t = *this;
    *this -= 1;
    return t;
}

Bigint operator*(const Bigint &a, const Bigint &b)
{
    Bigint ret;
    ret.len = a.len + b.len;
    ret.sign = !(a.sign ^ b.sign);
    for (int i = 0; i < a.len; i++)
        for (int j = 0; j < b.len; j++)
            ret.s[i + j] += a.s[i] * b.s[j];
    for (int i = 1; i < ret.len; i++)
    {
        ret.s[i] += ret.s[i - 1] / 10;
        ret.s[i - 1] %= 10;
    }
    ret.clean();
    return ret;
}

Bigint Bigint::operator*=(const Bigint &num)
{
    *this = *this * num;
    return *this;
}

Bigint operator/(const Bigint &a, const Bigint &b)
{
    Bigint ret;
    ret.len = a.len - b.len + 1;
    if (ret.len <= 0)
    {
        ret.len = 1;
        return ret;
    }
    ret.sign = !(a.sign ^ b.sign);
    Bigint ta = a, tb = b;
    ta.sign = tb.sign = true;
    Bigint t;
    t.len = 0;
    for (int i = ta.len - 1; i >= 0; i--)
    {
        for (int j = t.len++; j > 0; j--)
            t.s[j] = t.s[j - 1];
        t.s[0] = ta.s[i];
        t.clean();
        while (t >= tb)
        {
            ++ret.s[i];
            t -= tb;
        }
    }
    ret.clean();
    return ret;
}

Bigint Bigint::operator/=(const Bigint &num)
{
    *this = *this / num;
    return *this;
}

Bigint operator%(const Bigint &a, const Bigint &b)
{
    Bigint ret, ta = abs(a), tb = abs(b);
    ret = ta - (ta / tb * tb);
    ret.sign = a.sign;
    return ret;
}

Bigint Bigint::operator%=(const Bigint &num)
{
    *this = *this % num;
    return *this;
}

Bigint factorial(const Bigint &num)
{
    Bigint ret = 1;
    for (Bigint i = 2; i <= num; i++)
        ret *= i;
    return ret;
}

Bigint sqrt(const Bigint &num)
{
    if (num < 0)return -1;
    if (num <= 1)return num;
    Bigint l = 0, r = num, mid;
    while (l + 1 < r)
    {
        mid = (l + r) / 2;
        if (mid * mid > num)r = mid;
        else l = mid;
    }
    return l;
}

Bigint pow(const Bigint &a, const Bigint &b)
{
    Bigint ret = 1;
    for (int i = 1; i <= b; i++)
        ret *= a;
    return ret;
}

int main()
{
    Bigint a, b;
    cin >> a >> b;
    cout << a + b << endl << abs(a - b) << endl << a * b << endl << a / b << endl << a % b << endl;
    return 0;
}
