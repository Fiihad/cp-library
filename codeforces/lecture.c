#include<stdio.h>
#include<string.h>
int main (void)
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    char lec [m][2][11];
    for(i=0;i<m;i++) scanf("%s %s", lec[i][0],lec[i][1]);
    char in [11], out [n][11];
    for(i=0;i<n;i++){
        scanf("%s",in);
        for(j=0;j<m;j++){
            if(!strcmp(in,lec[j][0])){
                if(strlen(lec[j][0])>strlen(lec[j][1])) strcpy(out[i],lec[j][1]);
                else strcpy(out[i],lec[j][0]);
                break;
            }
        }
    }
    for(i=0;i<n;i++) i!=n-1?
    printf("%s ",out[i]):printf("%s\n",out[i]);
    return 0;
}