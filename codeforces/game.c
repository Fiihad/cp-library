#include<stdio.h>

int main (void)
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, x=0, i;
        scanf("%d", &n);
        int ara [n];
        for (i=0; i<n; i++){
            scanf("%d", &ara[i]);
        }
        for(i=2; i<n; i++){
            if(ara[i]==1 && ara[i-1]==0) x+=2;
            if(ara[i]==0 && ara[i-1]==0) x++;
        }
        printf("%d\n", x);
    }
    return 0;
}