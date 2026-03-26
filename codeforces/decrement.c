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

        int dif;
        for (int i=0; i<n; i++)
        {
            if (ara2[i]){
                dif = ara1[i] - ara2[i];
                break;
            }
            if (ara1[i] - ara2[i] > dif)
                dif = ara1[i] - ara2[i];
        }
        
        int i;
        for (i = 0; i < n; i++)
        {
            if (ara2[i] > ara1[i])
            {
                printf("NO\n");
                break;
            }
            if (ara2[i] == 0 && ara1[i] - ara2[i] > dif)
            {
                printf("NO\n");
                break;
            }
            if (ara2[i] && ara1[i] - ara2[i] != dif)
            {
                printf("NO\n");
                break;
            }
        }
        if (i == n)
            printf("YES\n");
    }

    return 0;
}