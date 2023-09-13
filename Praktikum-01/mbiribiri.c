#include <stdio.h>

#include "point.h"
#include "garis.h"

int main()
{
    GARIS L;
    POINT P;
    int n, i, total = 0;
    float b, d;
    scanf("%f", &b);
    BacaGARIS(&L);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        BacaPOINT(&P);
        d = JarakGARIS(L, P);
        if (d <= b)
        {
            total++;
        }
    }
    printf("%d\n", total);
    return 0;
}