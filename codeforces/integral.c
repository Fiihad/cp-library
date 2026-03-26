#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}

int exist(int x, int ara [], int n){
    for (int i=0; i<n; i++){
        if (x==ara[i]) return 1;
    }
    return 0;
}

int main (void)
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, c, yes=1;
        scanf("%d %d", &n, &c);
        int ara [n];
        for (int i=0; i<n; i++) scanf("%d", &ara[i]);
        if(exist(1, ara, n) == 0){
            printf("No\n");
            continue;
        }
        qsort(ara, n, sizeof(int), compare);

        for(int i=0; i<n-1; i++){
            if(!(exist(ara[i]/ara[i+1], ara, n))){
                printf("No\n");
                yes=0;
                break;
            }
        }
        if(!(yes)) continue;
        printf("Yes\n");
    }
    
    return 0;
}