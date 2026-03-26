#include <stdio.h>

int n, i, i2 = 1, k, recursion = 0, ara[20], ara2[20], count = 20, count2 = 0;

void recurs(int n)
{
    if (n < 10)
    {
        count2++;
        if (count2 < count)
        {
            count = count2;
            for (int i = 0; i < count; i++)
                ara[i] = ara2[i];
        }
    }
    for (i = 1; i < 10; i++)
    {
        if (n % i == 0)
        {
            ara2[count2] = i;
            count2++;
            recurs(n / i);
        }
    }
}

int main(void)
{
    scanf("%d", &n);

    for (k = n, i = 1; i < 10; i++)
    {
        if (!recursion)
            i2 = i;
        if (k % i == 0)
        {
            ara2[count2] = i;
            // printf("1. count2=%d i=%d\n", count2, i);
            count2++;
            if (k / i < 10)
            {
                recursion = 0;
                ara2[count2] = k / i;
                count2++;
                if (count2 < count)
                {
                    count = count2;
                    for (int i = 0; i < count; i++)
                        ara[i] = ara2[i];
                }
                count2 = 0;
                k = n;
                i = i2;
            }
            else
            {
                recursion = 1;
                k /= i;
                i = 1;
            }
            // printf("2. k=%d i=%d count2=%d i2=%d\n", k, i, count2, i2);
        }
    }

    if (count == 20)
        printf("-1\n");
    else
    {
        for (int i = 0; i < count; i++)
            printf("%d", ara[i]);
        printf("\n");
    }
    return 0;
}