#include <stdio.h>
#include <math.h>

typedef double (*integrand)(double);

double c_trap(integrand f,double a,double b,int n)
{
    double h=(b-a)/n,x=a,sum=0;
    int i;
    for (i=0;i<n;i++)
    {
        sum+=(h/2)*(f(x)+f(x+h));
        x+=h;
    }
    return sum;
}

double c_simp(integrand f,double a,double b,int n)
{
    double h=(b-a)/n,x=a,sum=0;
    int i;
    for (i=0;i<n;i++)
    {
        sum+=(h/6)*(f(x)+4*f(x+h/2)+f(x+h));
        x+=h;
    }
    return sum;
}

double c_cote(integrand f,double a,double b,int n)
{
    double h=(b-a)/n,x=a,sum=0;
    int i;
    for (i=0;i<n;i++)
    {
        sum+=(h/90)*(7*f(x)+32*f(x+h/4)+12*f(x+h/2)+32*f(x+3*h/4)+7*f(x+h));
        x+=h;
    }
    return sum;
}

double gauss_inv(integrand f, double a, double b)
{
    double weights[3]={5.0/9.0,8.0/9.0,5.0/9.0};
    double nodes[3]={-0.774596669,0.0,0.774596669};
    double x,sum=0;
    int i;
    for (i=0;i<3;i++)
    {
        x=((b-a)*nodes[i]+a+b)/2;
        sum+=weights[i]*f(x);
    }
    return (b-a)*sum/2;
}

double gauss(integrand f,double a,double b,int n)
{
    double h=(b-a)/n,x=a,sum=0;
    int i;
    for (i=0;i<n;i++)
    {
        sum+=gauss_inv(f,x,x+h);
        x=x+h;
    }
    return sum;
}