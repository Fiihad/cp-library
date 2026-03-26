/* 26-03-2022 */

#include <stdio.h>

int main(void)
{
    int i, j, temp, big, small;
    while (scanf("%d %d", &i, &j) != EOF)
    {
        int max = 0;
        big = i > j ? i : j;
        small = i + j - big;

        while (small <= big)
        {
            int count = 1;
            temp = small;
            while (temp != 1)
            {
                if (temp % 2)
                    temp = 3 * temp + 1;
                else
                    temp = temp / 2;
                count++;
            }
            if (count > max)
                max = count;
            small++;
        }
        printf("%d %d %d\n", i, j, max);
    }

    return 0;
}