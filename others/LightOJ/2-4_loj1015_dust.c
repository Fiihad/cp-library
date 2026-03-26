#include<stdio.h>

int main (void)
{
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        int n, dust, sum=0;
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d", &dust);
            if (dust>0) sum += dust;
        }
        printf("Case %d: %d\n", i, sum);
    }
    return 0;
}