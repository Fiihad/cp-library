/* 24-3-2022 */

#include <stdio.h>
#include <stdlib.h>

int cmpr(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    int k, max = 0, i, incr;
    long long j;
    scanf("%d", &k);
    int ara[k];

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &ara[i]);
        // if (ara[i] > max)
        // max = ara[i];
    }
    qsort(ara, k, sizeof(int), cmpr);

    for (i = 0, j = 1, incr=0; i<k ; incr++, j += incr)
    {
        if (j == ara[i])
        {
            printf("1 ");
            i++;
        }
        else if (j > ara[i])
        {
            printf("0 ");
            j -= incr--;
            i++;
        }
    }
    printf("\n");

    // char str[ara[0] + 1];
    // for (int i = 1, print1 = 1, printed1 = -1, print0 = 0; i <= max; i++)
    // {
    //     if (print1)
    //     {
    //         str[i] = '1';
    //         print1 = 0;
    //         printed1++;
    //         print0 = printed1;
    //         if(!print0) print1=1;
    //     }
    //     else
    //     {
    //         str[i] = '0';
    //         print0--;
    //         if (!print0)
    //             print1 = 1;
    //     }
    // }

    // for(int i=0; i<k; i++) printf("%c ", str[ara[i]]);
    // printf("\n");

    return 0;
}