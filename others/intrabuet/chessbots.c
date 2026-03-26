#include<stdio.h>

int main (void)
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, i, j, k;
        scanf("%d", &n);
        int ara[n+1];
        for(i=1; i<=n; i++) ara[i]=1;
        int cnt = (n*(n-1))/2;
        while (cnt--)
        {
            scanf("%d %d %d", &i, &j, &k);
            if (k==i){
                if (ara[i]<=ara[j]) ara[i]=ara[j]+1;
            }
            else if (k==j){
                if (ara[j]<=ara[i]) ara[j]=ara[i]+1;
            }
            else{
                if (ara[i]<ara[j]) ara[i]=ara[j];
                else ara[j]=ara[i];
            }
        }
        int temp, min=ara[1];
        for(i=2; i<=n; i++) if(ara[i]<min) min = ara[i];

        if(min==1)
            for(i=1; i<=n; i++) printf("%d ", ara[i]);
        else for(i=1; i<=n; i++) printf("%d ", ara[i]-min+1);
        printf("\n");
    }
    
    return 0;
}