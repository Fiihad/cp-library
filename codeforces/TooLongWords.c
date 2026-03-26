#include<stdio.h>
#include<string.h>
int main (void)
{
    int t,l,i;
    char w[101];
    scanf("%d",&t);
    while(t--){
        scanf("%s",w);
        l=strlen(w);
        if(l>10) printf("%c%d%c\n",w[0],l-2,w[l-1]);
        else printf("%s\n",w);
    }
    return 0;
}