#include <iostream>
using namespace std;
double a,b,c,d;
double f(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
    cin >>a>>b>>c>>d;
    for (int i=-100;i<=100;i++)
    {
        double xx=i,xd=i+1,xm;
        if (f(xx)==0)printf ("%0.2lf ",xx);
        if (f(i)*f(i+1)<0)
        {
            while (xd-xx>=0.001)
            {
                xm=(xd+xx)/2;
                if (f(xx)*f(xm)<=0)
                xd=xm;
                else xx=xm;
            }
            printf ("%0.2lf ",xx);
        }
    }
    return 0;
}

