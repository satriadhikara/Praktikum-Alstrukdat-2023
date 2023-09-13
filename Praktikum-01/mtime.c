#include <stdio.h>

#include "time.h"

int main()
{
    int n, i;
    TIME T1, T2, TAwl, TAkh;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("[%d]\n", i + 1);
        BacaTIME(&T1);
        BacaTIME(&T2);
        if (i == 0)
        {
            TAwl = T1;
            TAkh = T2;
        }
        if (TGT(TAwl, T1))
        {
            TAwl = T1;
        }
        if (TLT(TAkh, T1))
        {
            TAkh = T1;
        }
        if (TGT(TAwl, T2))
        {
            TAwl = T2;
        }
        if (TLT(TAkh, T2))
        {
            TAkh = T2;
        }
        if (TGT(T1, T2))
        {
            printf("%ld\n", TIMEToDetik(T1) - TIMEToDetik(T2));
        }
        else
        {
            printf("%ld\n", TIMEToDetik(T2) - TIMEToDetik(T1));
        }
    }
    TulisTIME(TAwl);
    printf("\n");
    TulisTIME(TAkh);
    printf("\n");
}