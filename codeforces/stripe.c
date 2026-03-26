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
        int count = 0, max = 0, max_ind, alt = 0, i, l = 1, j = 1;

        for (int i = 0; i < n; i++)
        {
            scanf(" %c", &c[i]);
            if (c[i] == 'B')
            {
                count++;
                if (count > max)
                {
                    max = count;
                    max_ind = i;
                }
            }
            else
                count = 0;
        }

        while (1)
        {
            count = 0;
            if (alt)
            {
                if (max_ind + j >= n)
                {
                    alt = 0;
                    continue;
                }

                c[max_ind + j++] = 'B';
                for (i = max_ind + j; i<n && c[i] != 'W'; i++)
                    count++;
                if (max + count +1 >= k)
                {
                    printf("%d\n", j-1);
                    break;
                }
                alt = 0;
            }
            else
            {
                if (max_ind - max + 1 - l < 0)
                {
                    alt = 1;
                    continue;
                }

                c[max_ind - max + 1 - l++] = 'B';
                for (i = max_ind - max + 1 - l; i >= 0 && c[i] != 'W'; i--)
                    count++;
                if (max + count + 1 >= k)
                {
                    printf("%d\n", count+1);
                    break;
                }
                alt = 1;
            }
        }

        // printf("%d %d\n", max, max_ind);
    }

    return 0;
}