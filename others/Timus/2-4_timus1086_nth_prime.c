/* 23-03-2011 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    int primes[15001] = {0, 2}; // array to store already counted primes
    // array initialized by zero. 2 is the first prime number, added manually to avoid complications
    int k;
    scanf("%d", &k);
    while (k--)
    {
        int n, i, check, count = 1, not = 0;
        scanf("%d", &n);

        for (check = 3; count < n; check += 2) 
        // checking will be started with 3 as 2 is added manually. only odd numbers will be checked
        {
            // printf("check=%d count=%d\n", check, count);
            if (primes[count + 1] != 0) // checking will be avoided for already existing numbers
            {
                count++;
                check = primes[count];
                continue;
            }
            int sq = sqrt(check);
            for (i = 1; primes[i] <= sq; i++)
            // for checking the number will be devided by only prime numbers till its sqrt
            {
                // printf("primes[%d]=%d\n", i, primes[i]);
                if (check % primes[i] == 0)
                {
                    not = 1;
                    break;
                }
            }
            if (!not )
            {
                count++;
                primes[count] = check;
            }
            not = 0;
        }
        printf("%d\n", primes[count]);
    }

    return 0;
}