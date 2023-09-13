#include <stdio.h>

#include "liststatik.h"

int main()
{
    ListStatik l1, l2;
    int i, j, total = 0, kertas = 0, besi = 0, glass = 0, ik = -1, ib = -1, ig = -1;
    CreateListStatik(&l1);
    CreateListStatik(&l2);
    readList(&l1);
    readList(&l2);
    for (i = 0; i < listLength(l1); i++)
    {
        if (ELMT(l1, i) == 1)
        {
            ib = i;
            besi += 1;
        }
        if (ELMT(l1, i) == 2)
        {
            ik = i;
            kertas += 1;
        }
        if (ELMT(l1, i) == 3)
        {
            ig = i;
            glass += 1;
        }
    }
    total = (besi + kertas + glass);
    if (ib != -1)
    {
        for (i = 1; i <= ib; i++)
        {
            total += (ELMT(l2, i - 1) * 2);
        }
    }

    if (ik != -1)
    {
        for (i = 1; i <= ik; i++)
        {
            total += (ELMT(l2, i - 1) * 2);
        }
    }

    if (ig != -1)
    {
        for (i = 1; i <= ig; i++)
        {
            total += (ELMT(l2, i - 1) * 2);
        }
    }

    printf("%d\n", total);
    return 0;
}