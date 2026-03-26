#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        char c[n];
        scanf("%s", c);

        int max=0, count=0;
        for (int i=0, j=0; i<n; i++)
        {
            if (c[i]=='B')
                count++;

            if (count>max)
                max = count;
        }

        printf("%d\n", k-max);
    }
}