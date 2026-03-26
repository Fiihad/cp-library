/* 24-3-2022 */

#include<stdio.h>
#include<math.h>

int main (void)
{
    int t;
    scanf("%d", &t);

    for (int i=1; i<=t; i++)
    {
        long long n;
        scanf("%d", &n);

        long long col, row;

        int root = sqrt(n);
        if (root*root!=n) root++;
        long long sq_high = root*root;
        int dif = sq_high - n;

        if (sq_high%2){
            if (dif < root){
                row = root;
                col = 1 + dif;
            }
            else{
                col = root;
                row = root - ((sq_high-root+1) - n);
            }
        }
        else{
            if (dif < root){
                col = root;
                row = 1 + dif;
            }
            else{
                row = root;
                col = root - ((sq_high-root+1) - n);
            }
        }

        printf("Case %d: %lld %lld\n", i, col, row);
    }
    

    return 0;
}