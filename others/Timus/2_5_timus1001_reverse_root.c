#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int i;
    double in[131073];
    for (i = 0;; i++)
    {
        if (scanf("%lf", in+i) == EOF) break;
        in[i] = sqrt(in[i]);
    }
    while (i--)
        printf("%lf\n", in[i]);

    return 0;
}