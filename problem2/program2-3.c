// Secant method
#include <stdio.h>
#include <math.h>

double f1(double x);
double f2(double x);

int main()
{
    int n=0;
    double x=-1,y=0,z;
    while(fabs(x-y)>0.5e-8)
    {
        z=x;
        x=x-((x-y)*f1(x))/(f1(x)-f1(y));
        y=z;
        n++;
    }
    printf("%.8lf %d\n",x,n);
    x=1;
    y=2;
    n=0;
    while(fabs(x-y)>0.5e-8)
    {
        z=x;
        x=x-((x-y)*f2(x))/(f2(x)-f2(y));
        y=z;
        n++;
    }
    printf("%.8lf %d\n",x,n);
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