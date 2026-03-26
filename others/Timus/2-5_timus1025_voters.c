#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main (void)
{
    int n;
    scanf("%d", &n);
    int ara[n];
    for (int i=0; i<n; i++)
        scanf("%d", &ara[i]);

    qsort(ara, n, sizeof(int), cmpfunc);

    int sum=0;
    for (int i=0; i<n/2+1; i++){
        // printf("%d %d\n", sum, ara[i]);
        sum += (ara[i]/2+1);
    }

    printf("%d\n", sum);
    return 0;
}