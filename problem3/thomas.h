#include <stdio.h>

void tridiag(double *a,double *b,double *c,double *x,double *y,int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        b[i]+=-a[i-1]*c[i-1]/b[i-1];
        y[i]+=-a[i-1]*y[i-1]/b[i-1];
    }
    x[n-1]=y[n-1]/b[n-1];
    for(i=n-2;i>=0;i--)
    {
        x[i]=(y[i]-c[i]*x[i+1])/b[i];
    }
}

void cyctridiag(double *a,double *b,double *c,double *x,double *y,int n)
{
    const int ord=n;
    double u[ord-1],v[ord-1],y1[ord-1],y2[ord-1];
    y1[0]=-a[0];
    y1[n-1]=-c[n-2];
    int i;
    for(i=1;i<n-1;i++)
    {
        y1[i]=0;
    }
    for(i=0;i<n-1;i++)
    {
        y2[i]=y[i];
    }
    tridiag(a+1,b,c,u,y1,n-1);
    tridiag(a+1,b,c,v,y2,n-1);
    x[n-1]=(y[n-1]-c[n-1]*v[0]-a[n-1]*v[n-2])/(b[n-1]+c[n-1]*u[0]+a[n-1]*u[n-2]);
    for(i=0;i<n-1;i++)
    {
        x[i]=u[i]*x[n-1]+v[i];
    }
}