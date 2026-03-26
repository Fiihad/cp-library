#include<stdio.h>

int counting (int n)
{
    if (n%3==2) return n/3*2 +1;
    else return n/3*2;

}

int main (void)
{
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        int a, b;
        int count=0;
        scanf("%d %d", &a, &b);
        // for(int k=a; k<=b; k++)
        // {
        //     if (k%3==0 || (k+1)%3==0) count++;
        // }
        count = counting(b) - counting(a-1);
        printf("Case %d: %d\n", i, count);
    }
    return 0;
}