#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);
        int ara1[n], ara2[n];

        for (int i = 0; i < n; i++)
            scanf("%d", &ara1[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &ara2[i]);

        int time;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || ara2[i - 1] < ara1[i])
                time = ara2[i] - ara1[i];
            else
                time = ara2[i] - ara2[i-1];

            printf("%d ", time);
        }
        printf("\n");
    }
    return 0;
}