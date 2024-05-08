#include <stdio.h>

double acc(float N);
float inc(float N);
float dec(float N);

int main()
{
    // 10^2
    printf("%.8f %.8f %.8f\n",acc(1.0e2),inc(1.0e2),dec(1.0e2));
    // 10^4
    printf("%.8f %.8f %.8f\n",acc(1.0e4),inc(1.0e4),dec(1.0e4));
    // 10^6
    printf("%.8f %.8f %.8f\n",acc(1.0e6),inc(1.0e6),dec(1.0e6));
    return 0;
}

// accurate value
double acc(float N)
{
    return 0.5*(1.5-1.0/N-1.0/(N+1));
}

// function to compute the series increasingly
float inc(float N)
{
    float i;
    float ret=0;
    for(i=2;i<=N;i++)
    {
        ret+=1.0/(i*i-1.0);
    }
    return ret;
}

// function to compute the series decreasingly
float dec(float N)
{
    float i;
    float ret=0;
    for(i=N;i>=2;i--)
    {
        ret+=1.0/(i*i-1.0);
    }
    return ret;
}