#include<stdio.h>

int main (void)
{
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        int n, count=0;
        scanf("%d", &n);
        while (n)
        {
            if (n & 1) count++;
            n >>= 1;
        }
        if (count % 2) printf("Case %d: odd\n", i);
        else printf("Case %d: even\n", i);
    }
    return 0;
}