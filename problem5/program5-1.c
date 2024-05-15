#include <stdio.h>
#include <math.h>
#include <string.h>

typedef double (*integrand)(double);


double c_trap(integrand f,double a,double b,int n);
double c_simp(integrand f,double a,double b,int n);
double c_cote(integrand f,double a,double b,int n);
double gauss(integrand f,double a,double b,int n);

int main()
{
    // Input integrand
    integrand func;
    char fun[10];
    printf("Choose a function, sine or cosine:");
    scanf("%s",fun);
    if (strcmp(fun,"sin")==0) func=sin;
    else if (strcmp(fun,"cos")==0) func=cos;
    else {
        printf("You should type in \"sin\" or \"cos\".\n");
        return 0;
    }

    // Input method
    double (*method)(integrand,double,double,int);
    char meth[10];
    printf("Choose a method, trapzoidal, Simpson, Cotes or Gauss:");
    scanf("%s",meth);
    if (strcmp(meth,"trap")==0) method=c_trap;
    else if (strcmp(meth,"simp")==0) method=c_simp;
    else if (strcmp(meth,"cote")==0) method=c_cote;
    else if (strcmp(meth,"gauss")==0) method=gauss;
    else {
        printf("You should type in \"trap\", \"simp\", \"cote\" or \"gauss\".\n");
        return 0;
    }

    // Compute integral
    double a,b,integral;
    int n;
    printf("Please input the interval [a,b] and steps:");
    scanf("%lf %lf %d",&a,&b,&n);
    integral=method(func,a,b,n);
    printf("The integral is %lf\n",integral);
    return 0;
}

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

double gauss(integrand f,double a,double b,int n)
{
    return 3;
}