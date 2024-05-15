// Newton method with Aikten acceleration
#include <stdio.h>
#include <math.h>

double f1(double x);
double df1(double x);
double itf1(double x);
double f2(double x);
double df2(double x);
double itf2(double x);

int main()
{
    int n=0;
    double x=-1,y=1;
    while (fabs(y)>1e-8)
    {
        y=(x*itf1(itf1(x))-itf1(x)*itf1(x))/(x-2*itf1(x)+itf1(itf1(x)))-x;
        x+=y;
        n++;
    }
    printf("%.8lf %d\n",x,n);
    x=2;
    y=1;
    n=0;
    while (fabs(y)>1e-8)
    {
        y=(x*itf2(itf2(x))-itf2(x)*itf2(x))/(x-2*itf2(x)+itf2(itf2(x)))-x;
        x+=y;
        n++;
    }
    printf("%.8lf %d\n",x,n);
    return 0;
}

double f1(double x)
{
    return (sin(x)-6.0*x-5.0);
}

double df1(double x)
{
    return (cos(x)-6.0);
}

double itf1(double x)
{
    return (x-f1(x)/df1(x));
}

double f2(double x)
{
    return (log(x)+x*x-3.0);
}

double df2(double x)
{
    return (1/x+2*x);
}

double itf2(double x)
{
    return (x-f2(x)/df2(x));
}