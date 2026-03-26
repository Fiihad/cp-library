/* JUICE IN THE GLASS LOJ-1216 15-04-22 */

#include<stdio.h>
#include<math.h>

int main (void)
{
    short t;
    double pi = acos(-1);
    scanf("%hd", &t);
    for(int cases=1; cases<=t; cases++)
    {
        double r1, r2, h, p;
        scanf("%lf %lf %lf %lf", &r1, &r2, &h, &p);
        r1 = r2 + p*(r1-r2)/h;
        printf("Case %hd: %lf\n", cases, pi/3*p*(r1*r1+r2*r2+r1*r2));
    }

    return 0;
}