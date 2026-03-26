#include<stdio.h>

int main (void)
{
    int n, i, j, incr;
    scanf("%d", &n);
    int ara[n];
    for(i=0; i<n; i++) scanf("%d", &ara[i]);

    for(i=0; i<n; i++){
        for(j=1, incr=0;; incr++, j+=incr){
            if(j==ara[i]){
                printf("1 ");
                break;
            }
            if(j>ara[i]){
                printf("0 ");
                break;
            }
        }
    }
    printf("\n");

    return 0;
}