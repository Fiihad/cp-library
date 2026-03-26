#include <stdio.h>

int main(void)
{
    int n, m, sum = 0;
    scanf("%d %d", &n, &m);
    int min[m], max[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &min[i], &max[i]);
        sum += min[i];
    }

    if (sum > n)
    {
        printf("-1\n");
        return 0;
    }
    if (sum == n)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", min[i]);
        printf("\n");
        return 0;
    }
    for (int j = 0;;)
    {
        min[j]++;
        sum++;
        if (sum == n)
        {
            for (int i = 0; i < m; i++)
                printf("%d ", min[i]);
            printf("\n");
            return 0;
        }
        if (min[j] == max[j])
            j++;
        if (j == m-1)
        {
            printf("-1\n");
            return 0;
        }
    }

    return 0;
}