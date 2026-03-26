#include <stdio.h>

int main (void)
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, m, count=0;
        scanf("%d %d", &n, &m);

        int carr[n][3];
        for (int i=0; i<n; i++){
            count++;
            carr[i][1] = 0;
            scanf("%d", &carr[i][0]);
            if (i){
                if (carr[i][0] == carr[i-1][0])
                    count--;
                if (carr[i][0] > carr[i-1][0]){
                    carr[i][2] = carr[i][0];
                    carr[i][1] = 1;
                    carr[i][0] = carr[i-1][0];
                    count--;
                }
            }
        }

        
        while (m--)
        {
            int k, d;
            scanf("%d %d", &k, &d);

            int temp = carr[k-1][0];
            if (carr[k-1][1]) carr[k-1][0] = carr[k-1][2] - d;
            else carr[k-1][0] -= d;

            if (k-1)
            {
                if (carr[k-1] < carr[k-2]){
                    if (temp==carr[k-2]) count++;

                    if (k<n)
                        if (carr[k][0] >= carr[k-1][0]){
                            carr[k][1] = 1;
                            carr[k][2] = carr[k][0];
                            carr[k][0] = carr[k-1][0];
                            count--;
                        }
                }
            }

            printf("%d ", count);
            
        }
        printf("\n");


       printf("%d\n", count);
    }
    return 0;
}