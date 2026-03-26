#include <stdio.h>
#include<math.h>

double angle(double a, double b, double c)
{
    return acos((a*a+b*b-c*c)/(2*a*b));
}
double area(double a, double theta)
{
    return 0.5*a*a*theta;
}

int main(void)
{
    int t;
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases++)
    {
        double r1, r2, r3;
        scanf("%lf %lf %lf", &r1, &r2, &r3);

        double s = (r1+r2+r3);
        double triangle = sqrt(s*(s-r1-r2)*(s-r2-r3)*(s-r3-r1));
        double out = triangle - area(r1, angle(r1+r2, r1+r3, r2+r3)) - area(r2, angle(r1+r2, r2+r3, r1+r3)) - area(r3, angle(r1+r3, r2+r3, r1+r2));

        printf("Case %d: %lf\n", cases, out);
    }

    return 0;
}