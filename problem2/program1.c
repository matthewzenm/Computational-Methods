// Bisection method
#include <stdio.h>
#include <math.h>

double f1(double x);
double f2(double x);
int sgn(double x);

int main()
{
    double a=-1.0,b=0.0;
    while(b-a>1e-8)
    {
        if (sgn(f1(a)*sgn(f1((a+b)/2)))<0) b=(b+a)/2;
        else a=(a+b)/2;
    }
    printf("%.8lf\n",(a+b)/2);
    a=1.0;
    b=2.0;
    while(b-a>1e-8)
    {
        if (sgn(f2(a)*sgn(f2((a+b)/2)))<0) b=(b+a)/2;
        else a=(a+b)/2;
    }
    printf("%.8lf\n",(a+b)/2);
    return 0;
}

double f1(double x)
{
    return (sin(x)-6.0*x-5.0);
}

double f2(double x)
{
    return (log(x)+x*x-3.0);
}

int sgn(double x)
{
    if (x>0) return 1;
    else if (x=0) return 0;
    else return -1;
}