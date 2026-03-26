#include<stdio.h>
#include<math.h>

int main (void)
{
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        float r, pi = 2*acos(0.0);
        scanf("%f", &r);

        printf("Case %d: %.2f\n", i, 4*r*r - pi*r*r);
    }
    return 0;
}