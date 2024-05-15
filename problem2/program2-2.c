// Newton method
#include <stdio.h>
#include <math.h>

double f1(double x);
double df1(double x);
double f2(double x);
double df2(double x);

int main()
{
    int n=0;
    double x=-1;
    while (fabs(f1(x)/df1(x))>1e-8)
    {
        x=x-f1(x)/df1(x);
        n++;
    }
    printf("%.8lf %d\n",x,n);
    x=2;
    n=0;
    while (fabs(f2(x)/df2(x))>1e-8)
    {
        x=x-f2(x)/df2(x);
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

double f2(double x)
{
    return (log(x)+x*x-3.0);
}

double df2(double x)
{
    return (1/x+2*x);
}