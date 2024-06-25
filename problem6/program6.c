#include "ode.h"

double equation(double x,double y)
{
    return -x*x*y*y;
}

double solution(double x)
{
    return 3/(1+x*x*x);
}

int main(int argc,char *argv[])
{
    int n,method;
    printf("Input number of intervals:");
    scanf("%d",&n);
    printf("Input method, 1 for Euler, 2 for modified Euler, 3 for Runger-Kutter:");
    scanf("%d",&method);
    eq rhs=equation;
    func sol=solution;
    if (method==1) euler(rhs,sol,0,3,1.5,n);
    else if (method==2) modeuler(rhs,sol,0,3,1.5,n);
    else if (method==3) rk(rhs,sol,0,3,1.5,n);
    else printf("Error!");
    return 0;
}