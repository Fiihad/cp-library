#include<stdio.h>
#include<string.h>
int main (void)
{
    int deb=0;
    int t;
    scanf("%d",&t);
    while(t--){
        int i,j,k,m=0;
        char a[20], b[20], c[20];
        scanf("%s %s",a,c);
        int la=strlen(a); int lc=strlen(c);
        
        for(i=la-1,j=lc-1,k=0; i>=0; i--,j--,k++){
            if(j<0){
                printf("-1\n");
                m++;
                break;
            }
            if(c[j]>=a[i]){
                b[k]=(c[j]-48)-(a[i]-48)+48;
                if(deb) printf("b[%d]=%c,%d\n",k,b[k],b[k]);
            }
            else{
                b[k]= (c[j-1]-48)*10+(c[j]-48)-(a[i]-48)+48;
                if (b[k]>'9'||b[k]<'0'){
                    printf("-1\n");
                    m++;
                    break;
                }
                if(deb) printf("b[%d]=%c,%d\n",k,b[k],b[k]);
                j--;
            }
            if(i==0 && j!=0) {
                a[i]='0';
                i++;
            }
        }
        if(m) continue;
        b[k]='0';
        for(;b[k]=='0';k--) b[k]='\0';
        if(deb) printf("k=%d %s\n",k,b);
        printf("%s\n",strrev(b));
    }
    return 0;
}