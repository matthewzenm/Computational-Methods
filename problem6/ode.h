#include<stdio.h>
#include<math.h>

#define MAX 1e5

typedef double (*eq)(double,double);
typedef double (*func)(double);

void euler(eq rhs,func sol,double t0,double y0,double t_end,int n)
{
    if (n>=MAX)
    {
        printf("Overflow!");
        return;
    }
    double h=(t_end-t0)/n;
    double t=t0,y=y0,dy=0,R=0;
    int i;
    printf("t=%lf, y=%lf\n",t0,y0);
    for (i=0;i<=n;i++)
    {
        y+=h*rhs(t,y);
        printf("t=%lf, y=%lf\n",t,y);
        t+=h;
    }
    R=(sol(t0+h)-sol(t0)-h*rhs(t0,sol(t0)))/(h*h);
    printf("R=%lf\n",R);
}

void modeuler(eq rhs,func sol,double t0,double y0,double t_end,int n)
{
    if (n>=MAX)
    {
        printf("Overflow!");
        return;
    }
    double h=(t_end-t0)/n;
    double t=t0,y=y0,dy=0,R=0;
    int i;
    printf("t=%lf, y=%lf\n",t0,y0);
    for (i=0;i<=n;i++)
    {
        y+=h*(rhs(t,y)+rhs(t+h,y+h*rhs(t,y)))/2;
        printf("t=%lf, y=%lf\n",t,y);
        t+=h;
    }
    R=(sol(t0+h)-sol(t0)-h*(rhs(t0,y0)+rhs(t0+h,y0+h*rhs(t0,y0)))/2)/(h*h*h);
    printf("R=%lf\n",R);
}

void rk(eq rhs,func sol,double t0,double y0,double t_end,int n)
{
    if (n>=MAX)
    {
        printf("Overflow!");
        return;
    }
    double h=(t_end-t0)/n;
    double t=t0,y=y0,dy=0,R=0;
    double k1,k2,k3,k4;
    int i;
    printf("t=%lf, y=%lf\n",t0,y0);
    for (i=0;i<=n;i++)
    {
        k1=rhs(t,y);
        k2=rhs(t+h/2,y+h*k1/2);
        k3=rhs(t+h/2,y+h*k2/2);
        k4=rhs(t+h,y+h*k3);
        y+=h*(k1+2*k2+2*k3+k4)/6;
        printf("t=%lf, y=%lf\n",t,y);
        t+=h;
    }
    k1=rhs(t0,y0);
    k2=rhs(t0+h/2,y0+h*k1/2);
    k3=rhs(t0+h/2,y0+h*k2/2);
    k4=rhs(t0+h,y0+h*k3);
    R=(sol(t0+h)-sol(t0)-h*(k1+2*k2+2*k3+k4)/6)/(h*h*h*h);
    printf("R=%lf\n",R);
}