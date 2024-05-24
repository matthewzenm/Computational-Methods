/*
This is an alternative testing file.
*/

#include "integral.h"
#include <string.h>

double intpow(double x,int n)
{
    int i;
    double prod=1;
    for (i=0;i<n;i++)
    {
        prod*=x;
    }
}

double int10pow(double x)
{
    int i;
    double prod=1;
    for (i=0;i<10;i++)
    {
        prod*=x;
    }
}

double primint10pow(double x)
{
	int i;
	double prod=1;
	for (i=0;i<11;i++)
	{
		prod*=x;
	}
	return prod/11.0;
}

int main()
{
    // Input integrand
    integrand func;

    // Input method
    double (*method)(integrand,double,double,int);

    // Compute integral
    method=gauss;
    func=int10pow;
    double a,b,integral;
    int n;
    printf("Please input the interval [a,b] and steps:");
    scanf("%lf %lf %d",&a,&b,&n);
    integral=method(func,a,b,n);
    printf("The integral is %.8lf\n",integral);

    // Convergence order
    double err;
    err=fabs(primint10pow(b)-primint10pow(a)-integral)/intpow(b-a,6);
    printf("The pth (p=6) order relative error at %d steps is %.8lf\n",n,err);
    return 0;
}
