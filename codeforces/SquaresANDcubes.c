#include<stdio.h>
int main (void)
{
    int t,count,c;
    unsigned long int i,j,n;
    scanf("%d",&t);
    while(t--){
        c=1;
        count=0;
        scanf("%lu",&n);
        for(i=1;i*i<=n;i++){
            count++;
            if(c){
                for(;j<i*i;j++){
                    if(j*j*j>n) {
                        c=0;
                        break;}
                    count++;
                }
            j=i*i+1;}
        }
        printf("%d\n",count);
    }
    return 0;
}