#include <stdio.h>

int main()
{
    int n, m, i;
    scanf("%d", &n);
    scanf("%d", &m);
    for (i = 1; i <= n; i += 1)
    {
        if ((i % m) == 0)
        {
            printf("happy\n");
        }
        else
        {
            printf("%d\n", i);
        }
    }
    return 0;
}