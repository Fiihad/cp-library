#include<stdio.h>
int main (void)
{
    int t,x,y,z,temp;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&x,&y,&z);
        if(x==y&&z%2==0){
            printf("YES\n");
            continue;
        }
        else if(x==z&&y%2==0){
            printf("YES\n");
            continue;
        }
        else if(z==y&&x%2==0){
            printf("YES\n");
            continue;
        }
        else if(y>x&&y>z) {temp=y;y=x;x=temp;}
        else if(z>x&&z>y) {temp=z;z=x;x=temp;}
        if(x-y==z) {printf("YES\n"); continue;}
        printf("NO\n");
    }
    return 0;
}