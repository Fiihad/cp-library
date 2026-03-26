#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        float m, n;
        scanf("%f %f", &m, &n);
        int ans = ceil((m*n)/2.0);
        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}