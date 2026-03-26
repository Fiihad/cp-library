#include<stdio.h>

int main (void)
{
    int t;
    scanf("%d", &t);
    for (int cases=1; cases<=t; cases++)
    {
        unsigned n, count=0;
        scanf("%u", &n);

        for (int i=0; i<8*sizeof(int); i++)
        {
            if (n & (1<<i))
            {
                if (!(n&(1<<(i+1))))
                {
                    n ^= 1<<i;
                    n ^= 1<<(i+1);
                    break;
                }
                else
                {
                    n ^= 1<<i;
                    n ^= 1<<count;
                    count++;
                }
            }
        }
        printf("Case %d: %u\n", cases, n);
    }
    return 0;
}