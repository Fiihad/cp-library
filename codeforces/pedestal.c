#include <stdio.h>
#include <math.h>

int main (void)
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        int temp, b, a, c;
        a = ceil(((double)n)/3) + 1;
        c = n/3 - 1;
        b = n - a - c;

        printf("%d %d %d\n", b, a, c);
    }
    
    return 0;
}