#include<stdio.h>

int main (void)
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, h, i, count=0, end;
        scanf("%d %d", &n, &h);
        int dec[n], inc[n];
        for(i=0; i<n; i++) scanf("%d", &dec[i]);
        for(i=0; i<n; i++) scanf("%d", &inc[i]);

        for(i=0;;i++){
            if(i==0) end=0;
            if(dec[i]>h || dec[i]==-1){
                end++;
                if(i==n-1) i=-1;
                if(end==n) break;
                continue;
            }
            h-=dec[i];
            h+=inc[i];
            count++;
            dec[i]=-1;
            if(i==n-1) i=-1;
            // printf("%d %d %d %d\n", i, h, count, end);
        }
        printf("%d\n", count);
    }
    return 0;
}