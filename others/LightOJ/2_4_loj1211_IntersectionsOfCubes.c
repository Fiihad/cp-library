#include<stdio.h>

int main (void)
{
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        int cubes, low_edge[3], high_edge[3], max[3], min[3];
        for (int j=0; j<3; j++){
            max[j] = 0;
            min[j] = 1000;
        }
        scanf("%d", &cubes);

        while (cubes--)
        {
            for (int j=0; j<3; j++){
                scanf("%d", &low_edge[j]);
                if (low_edge[j] > max[j]) max[j] = low_edge[j];
            }
            for (int j=0; j<3; j++){
                scanf("%d", &high_edge[j]);
                if (high_edge[j] < min[j]) min[j] = high_edge[j];
            }
        }

        long long volume=1;
        for (int j=0; j<3; j++){
            volume *= (min[j]-max[j]);
        }
        if (volume<0) volume = 0;
        printf("Case %d: %lld\n", i, volume);
    }
    return 0;
}