#include <stdio.h>

int main (void)
{
    int t;
    scanf("%d", &t);

    if (t%2 || t==2) printf("NO\n");
    else printf("YES\n");
    return 0;
}