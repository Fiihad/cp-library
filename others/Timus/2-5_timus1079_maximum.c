#include<stdio.h>
#include<math.h>

int main (void)
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n==0) break;

        if (n<3)
        {
            printf("1\n");
            continue;
        }
        n = (n-3)/2;

        for (int i=0;; i++)
        {
            if (pow(2,i) > n)
            {
                printf("%d\n", i+2);
                break;
            }
            n -= pow(2,i);
        }
    }
    
    return 0;
}