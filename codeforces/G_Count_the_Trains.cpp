#include <bits/stdc++.h>
 
int main (void)
{
    int t;
    scanf("%d", &t);
 
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
 
        int carr[n];
        for (int i=0; i<n; i++)
            scanf("%d", &carr[i]);
 
        while (m--)
        {
            int k, d, count=1;
            scanf("%d %d", &k, &d);
 
            carr[k-1] -= d;
            int temp[n];
            for (int i=0; i<n; i++)
                temp[i] = carr[i];
 
            for (int i=1; i<n; i++)
            {
                count++;
                if (temp[i] >= temp[i-1])
                {
                    temp[i] = temp[i-1];
                    count--;
                }
            }
            printf("%d ", count);
            
        }
        printf("\n");
    }
    return 0;
}