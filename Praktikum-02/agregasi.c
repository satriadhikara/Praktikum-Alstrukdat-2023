#include <stdio.h>

#include "liststatik.h"

int main()
{
    ListStatik l;
    int x, i, max, min, median;
    float mean = 0;
    CreateListStatik(&l);
    readList(&l);
    scanf("%d", &x);
    sortList(&l, true);
    printList(l);
    printf("\n");
    for (i = 0; i < listLength(l); i++)
    {
        mean += ELMT(l, i);
    }
    mean /= listLength(l);
    printf("Average: %0.2f\n", mean);
    if (indexOf(l, x) != IDX_UNDEF)
    {
        printf("%d\n", indexOf(l, x));
        extremeValues(l, &max, &min);
        if (x == max)
        {
            printf("X maksimum\n");
        }
        if (x == min)
        {
            printf("X minimum\n");
        }
        if (listLength(l) % 2 == 0)
        {
            median = ELMT(l, (listLength(l) / 2 - 1));
        }
        else
        {
            median = ELMT(l, (listLength(l) / 2));
        }
        if (x == median)
        {
            printf("X median\n");
        }
    }
    else
    {
        printf("%d tidak ada\n", x);
    }
    return 0;
}