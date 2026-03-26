#include<stdio.h>
#include<math.h>

int main (void)
{
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        unsigned r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        if ((r1+c1)%2 != (r2+c2)%2)
            printf("Case %d: impossible\n", i);
        else{
            if (abs(r1-r2) == abs(c1-c2))
                printf("Case %d: 1\n", i);
            else printf("Case %d: 2\n", i);
        }
    }
    return 0;
}