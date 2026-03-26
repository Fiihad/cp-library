#include<stdio.h>
#include<stdlib.h>
int main (void)
{
    int n,q,t,k,d,i,fre,o;
    scanf("%d %d",&n,&q);
    int *ara;
    ara= (int*)calloc(n+1,sizeof(int));
    while(q--){
        scanf("%d %d %d",&t,&k,&d);
        for(fre=0,i=1;i<=n;i++) if(ara[i]<=t) fre++;
        if(fre>=k) for(fre=0,o=0,i=1;fre<k;i++){
            if(ara[i]<=t){
                fre++;
                o+=i;
                ara[i]=t+d;
                //printf("free=%d i=%d o=%d\n",fre,i,o);
            }
        }
        else o=-1;
        printf("%d\n",o);
    }
    free(ara);
    return 0;
}