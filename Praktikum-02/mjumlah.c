#include <stdio.h>
#include <math.h>

#include "liststatik.h"

int main()
{
    ListStatik l1, l2, l3;
    int i, t1 = 0, t2 = 0, temp, len1, len2;
    CreateListStatik(&l1);
    CreateListStatik(&l2);
    CreateListStatik(&l3);
    readList(&l1);
    readList(&l2);
    len1 = listLength(l1);
    len2 = listLength(l2);
    for (i = 0; i < len1; i++)
    {
        deleteLast(&l1, &temp);
        t1 += temp * pow(10, i);
    }
    for (i = 0; i < len2; i++)
    {
        deleteLast(&l2, &temp);
        t2 += temp * pow(10, i);
    }
    temp = t1 + t2;

    while (temp >= 10)
    {
        insertFirst(&l3, temp % 10);
        temp /= 10;
    }
    insertFirst(&l3, temp);
    printList(l3);
    printf("\n");
    return 0;
}