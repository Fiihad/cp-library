#include<stdio.h>
#include<math.h>

int main (void)
{
    int n, i;
    scanf("%d", &n);
    double ara[n];
    for(i=0; i<n; i++) scanf("%lf", &ara[i]);

    for(i=0; i<n; i++){
        double check = (1+sqrt(8*ara[i]-7))/2.0;
        if (check - (int)check == 0)
            printf("1 ");
        else printf("0 ");
    }
    printf("\n");

    return 0;
}