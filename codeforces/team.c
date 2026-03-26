#include<stdio.h>
int main (void)
{
    int n, count=0;
    scanf("%d",&n);
    while(n--){
        int p,q,r;
        scanf("%d %d %d",&p,&q,&r);
        if(p+q+r>1) count++;
    }
    printf("%d\n",count);
    return 0;
}