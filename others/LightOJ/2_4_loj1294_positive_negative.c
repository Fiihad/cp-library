#include<stdio.h>

int main (void)
{
    int t;
    scanf("%d", &t);
    for (int cases=1; cases<=t; cases++)
    {
        long long n, m, sum=0;
        scanf("%lld %lld", &n, &m);
        sum = m*m;
        printf("Case %d: %lld\n", cases, sum*(n/(2*m)));
    }
    return 0;
}