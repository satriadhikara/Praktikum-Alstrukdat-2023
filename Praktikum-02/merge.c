#include <stdio.h>

#include "liststatik.h"

int main()
{
    int i, j = 0, k = 0;
    ListStatik l1, l2, l3;
    CreateListStatik(&l1);
    CreateListStatik(&l2);
    CreateListStatik(&l3);
    readList(&l1);
    readList(&l2);
    sortList(&l1, true);
    sortList(&l2, true);
    for (i = 0; i < (listLength(l1) + listLength(l2)); i++)
    {
        if ((j == listLength(l2)) && (k == listLength(l1)))
        {
            break;
        }
        else if ((k == listLength(l1)) && !(j == listLength(l2)))
        {
            insertLast(&l3, ELMT(l2, j));
            j++;
        }
        else if ((j == listLength(l2)) && !(k == listLength(l1)))
        {
            insertLast(&l3, ELMT(l1, k));
            k++;
        }
        else if (ELMT(l2, j) <= ELMT(l1, k))
        {
            insertLast(&l3, ELMT(l2, j));
            j++;
        }
        else if (ELMT(l1, k) <= ELMT(l2, j))
        {
            insertLast(&l3, ELMT(l1, k));
            k++;
        }
    }
    printList(l3);
    printf("\n");
    return 0;
}