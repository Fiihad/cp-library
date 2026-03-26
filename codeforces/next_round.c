#include<stdio.h>
int main (void)
{
    int ara [50];
    int n, k, count=0, i;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&ara[i]);
    }
    for(i=0;ara[i]>=ara[k-1] && i<n;i++){
        if(ara[i]>0) count++;
        //printf("i=%d\t ara[i]=%d\t ara[k-1]=%d\t count=%d\n",i,ara[i],ara[k-1],count);
    }
    printf("%d\n",count);
    return 0;
}