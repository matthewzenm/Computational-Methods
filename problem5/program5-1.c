/*
Usage Instructions:
This program serves as a demonstration of universal functions defined in "integral.h" for computing numerical integrations.
The test functions for numerical integration are the sine and cosine functions.
When the first prompt appears, you should enter "sin" or "cos".
Following that, when the next prompt appears, you are to choose one of the following methods for computation: the composite trapezoidal rule, composite Simpson's rule, composite Cotes' rule, or composite Gauss rule. Enter "trap", "simp", "cote", or "gauss" respectively.
Finally, the last prompt will ask you to input the interval and the number of steps.
Once all these steps are completed, the program will output the value of the numerical integration and the relative error of order p, where p denotes the convergence order of the method.
*/

#include "integral.h"
#include <string.h>

double minuscos(double x)
{
    return -x;
}

double intpow(double x, int n)
{
    int i;
    double prod=1;
    for (i=0;i<n;i++)
    {
        prod*=x;
    }
}

int main()
{
    // Input integrand
    integrand func,primfunc;
    char fun[10];
    printf("Choose a function, sine or cosine:");
    scanf("%s",fun);
    if (strcmp(fun,"sin")==0){
        func=sin;
        primfunc=minuscos;
    }
    else if (strcmp(fun,"cos")==0){
        func=cos;
        primfunc=sin;
    }
    else {
        printf("You should type in \"sin\" or \"cos\".\n");
        return 0;
    }

    // Input method
    double (*method)(integrand,double,double,int);
    int conv;
    char meth[10];
    printf("Choose a method, trapzoidal, Simpson, Cotes or Gauss:");
    scanf("%s",meth);
    if (strcmp(meth,"trap")==0){
        method=c_trap;
        conv=2;
    }
    else if (strcmp(meth,"simp")==0){
        method=c_simp;
        conv=4;
    }
    else if (strcmp(meth,"cote")==0){
        method=c_cote;
        conv=6;
    }
    else if (strcmp(meth,"gauss")==0){
        method=gauss;
        conv=6;
    }
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
    printf("The integral is %.8lf\n",integral);

    // Convergence order
    double err;
    err=fabs(primfunc(b)-primfunc(a)-integral)/intpow(b-a,conv);
    printf("The pth (p=%d) order relative error at %d steps is %.8lf\n",conv,n,err);
    return 0;
}