#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main(void)
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int ara[n], out = 0;

        for (int i = 0; i < n; i++)
            scanf("%d", &ara[i]);

        qsort(ara, n, sizeof(int), cmpfunc);

        for (int i = 0; i < n; i++)
        {
            if (ara[i] != -1)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if ((ara[i] + ara[j]) % k == 0)
                    {
                        out += (ara[i] + ara[j]) / k;
                        ara[i] = ara[j] = -1;
                        // printf("%d ", out);
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (ara[i] != -1)
            {
                for (int j = n - 1; j > i; j--)
                {
                    if (ara[j] != -1)
                    {
                        out += (ara[i] + ara[j]) / k;
                        ara[i] = ara[j] = -1;
                        // printf("%d ", out);
                        break;
                    }
                }
            }
        }
        printf("%d\n", out);
    }

    return 0;
}