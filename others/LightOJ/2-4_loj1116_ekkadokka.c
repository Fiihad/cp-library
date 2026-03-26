#include <stdio.h>
#include <math.h>

int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        long long w, n, m;
        scanf("%lld", &w);

        if (w % 2){
            printf("Case %d: Impossible\n", i);
            continue;
        }
        for (m = 2; m <= w; m *= 2)
        {
            if (!(w % m))
            {
                if ((w / m) % 2)
                {
                    n = w / m;
                    break;
                }
            }
        }
        printf("Case %d: %lld %lld\n", i, n, m);
    }
    return 0;
}