#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int i;
    double *in;
    in = (double *)malloc(sizeof(double));
    for (i = 0;; i++)
    {
        in = (double *)realloc(in, 1 + i);
        if (scanf("%lf", in + i) == EOF)
            break;
        in[i] = sqrt(in[i]);
    }
    while (i--)
        printf("%lf\n", in[i]);

    free(in);
    return 0;
}