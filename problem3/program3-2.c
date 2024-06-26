#include "thomas.h"

int main()
{
    int n;
    printf("Input order of the matrix:");
    scanf("%d",&n);
    const int ord=n;
    double a[ord],b[ord],c[ord],x[ord],y[ord];
    int i;
    for(i=0;i<n;i++)
    {
        printf("Input a_%d:",i+1);
        scanf("%lf",a+i);
    }
    for(i=0;i<n;i++)
    {
        printf("Input b_%d:",i+1);
        scanf("%lf",b+i);
    }
    for(i=0;i<n;i++)
    {
        printf("Input c_%d:",i+1);
        scanf("%lf",c+i);
    }
    for(i=0;i<n;i++)
    {
        printf("Input y_%d:",i+1);
        scanf("%lf",y+i);
    }
    cyctridiag(a,b,c,x,y,ord);
    printf("The solution is:\n");
    for(i=0;i<n;i++)
    {
        printf("x_%d=%lf\n",i+1,x[i]);
    }
    return 0;
}