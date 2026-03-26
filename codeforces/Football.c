#include<stdio.h>
#include<string.h>
int main (void)
{
    char field [101];
    scanf("%s",field);
    int i,count=1,m=0,l=strlen(field);
    for (i=1;i<l;i++){
        if(field[i]==field[i-1]) count++;
        if(count>=7){
            m=1;
            break;
        }
        if(field[i]!=field[i-1]) count=1;
    }
    if(m) printf("YES\n");
    else printf("NO\n");
    return 0;
}