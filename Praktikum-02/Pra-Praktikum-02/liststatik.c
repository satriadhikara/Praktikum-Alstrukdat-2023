#include <stdio.h>
#include <math.h>

#include "liststatik.h"

void CreateListStatik(ListStatik *l)
{
    int i;
    for (i = 0; i < CAPACITY; i++)
    {
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l)
{
    int i = 0, panjang = 0;
    while (ELMT(l, i) != MARK && i < CAPACITY)
    {
        panjang += 1;
        i += 1;
    }
    return panjang;
}

IdxType getFirstIdx(ListStatik l)
{
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l)
{
    return (listLength(l) - 1);
}

boolean isIdxValid(ListStatik l, IdxType i)
{
    return (i >= 0 && i < CAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i)
{
    return (i >= 0 && i < listLength(l));
}

boolean isEmpty(ListStatik l)
{
    return (ELMT(l, 0) == MARK);
}

boolean isFull(ListStatik l)
{
    return (ELMT(l, CAPACITY - 1) != MARK);
}

void readList(ListStatik *l)
{
    CreateListStatik(l);
    int n, i, m;
    scanf("%d", &n);
    while (n < 0 || n > CAPACITY)
    {
        scanf("%d", &n);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);
        ELMT(*l, i) = m;
    }
}

void printList(ListStatik l)
{
    int i;
    printf("[");
    for (i = 0; i < listLength(l); i++)
    {
        printf("%d", ELMT(l, i));
        if (i != (listLength(l) - 1))
        {
            printf(",");
        }
    }
    printf("]");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus)
{
    int i;
    if (plus)
    {
        for (i = 0; i < listLength(l1); i++)
        {
            ELMT(l1, i) += ELMT(l2, i);
        }
    }
    else
    {
        for (i = 0; i < listLength(l1); i++)
        {
            ELMT(l1, i) -= ELMT(l2, i);
        }
    }
    return l1;
}

boolean isListEqual(ListStatik l1, ListStatik l2)
{
    boolean sama = true;
    int i;
    if (listLength(l1) == listLength(l2))
    {
        for (i = 0; i < listLength(l1); i++)
        {
            if (ELMT(l1, i) != ELMT(l2, i))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

int indexOf(ListStatik l, ElType val)
{
    int i;
    for (i = 0; i < listLength(l); i++)
    {
        if (ELMT(l, i) == val)
        {
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min)
{
    int i;
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for (i = 1; i < listLength(l); i++)
    {
        if (ELMT(l, i) > *max)
        {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min)
        {
            *min = ELMT(l, i);
        }
    }
}

void insertFirst(ListStatik *l, ElType val)
{
    int i;
    for (i = listLength(*l); i > 0; i--)
    {
        ELMT(*l, i) = ELMT(*l, i - 1);
    }

    ELMT(*l, 0) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx)
{
    int i;
    for (i = listLength(*l); i > idx - 1; i--)
    {
        ELMT(*l, i) = ELMT(*l, i - 1);
    }
    ELMT(*l, idx) = val;
}

void insertLast(ListStatik *l, ElType val)
{
    ELMT(*l, listLength(*l)) = val;
}

void deleteFirst(ListStatik *l, ElType *val)
{
    int i;
    *val = ELMT(*l, 0);
    for (i = 0; i < listLength(*l) - 1; i++)
    {
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    ELMT(*l, listLength(*l) - 1) = MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx)
{
    int i;
    *val = ELMT(*l, idx);
    for (i = idx; i < listLength(*l) - 1; i++)
    {
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    ELMT(*l, listLength(*l) - 1) = MARK;
}

void deleteLast(ListStatik *l, ElType *val)
{
    *val = ELMT(*l, listLength(*l) - 1);
    ELMT(*l, listLength(*l) - 1) = MARK;
}

void sortList(ListStatik *l, boolean asc)
{
    int i, j, swapped, temp;
    if (asc == true)
    {
        for (i = 0; i < listLength(*l) - 1; i++)
        {
            swapped = 0;
            for (j = 0; j < listLength(*l) - i - 1; j++)
            {
                if (ELMT(*l, j) > ELMT(*l, j + 1))
                {
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                    swapped = 1;
                }
            }
            if (swapped == 0)
            {
                break;
            }
        }
    }
    else
    {
        for (i = 0; i < listLength(*l) - 1; i++)
        {
            swapped = 0;

            for (int j = 0; j < listLength(*l) - i - 1; j++)
            {
                if (ELMT(*l, j) < ELMT(*l, j + 1))
                {
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                    swapped = 1;
                }
            }

            if (swapped == 0)
            {
                break;
            }
        }
    }
}