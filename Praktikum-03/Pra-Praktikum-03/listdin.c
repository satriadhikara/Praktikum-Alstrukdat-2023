#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "listdin.h"

void CreateListDin(ListDin *l, int capacity)
{
    NEFF(*l) = 0;
    BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
    CAPACITY(*l) = capacity;
}

void dealocateList(ListDin *l)
{
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

int listLength(ListDin l)
{
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l)
{
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l)
{
    return NEFF(l) - 1;
}

boolean isIdxValid(ListDin l, IdxType i)
{
    return (i >= 0) && (i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i)
{
    return (i >= 0) && (i < NEFF(l));
}

boolean isEmpty(ListDin l)
{
    return NEFF(l) == 0;
}

boolean isFull(ListDin l)
{
    return NEFF(l) == CAPACITY(l);
}

void readList(ListDin *l)
{
    int n, i, m;
    scanf("%d", &n);
    while (n < 0 || n > CAPACITY(*l))
    {
        scanf("%d", &n);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);
        ELMT(*l, i) = m;
    }
    NEFF(*l) = n;
}

void printList(ListDin l)
{
    int i;
    printf("[");
    for (i = 0; i < NEFF(l); i++)
    {
        if (i != NEFF(l) - 1)
        {
            printf("%d,", ELMT(l, i));
        }
        else
        {
            printf("%d", ELMT(l, i));
        }
    }
    printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
    int i;
    ListDin temp;
    CreateListDin(&temp, CAPACITY(l1));
    NEFF(temp) = NEFF(l1);
    if (plus)
    {
        for (i = 0; i < NEFF(l1); i++)
        {
            ELMT(temp, i) = ELMT(l1, i) + ELMT(l2, i);
        }
        return temp;
    }
    else
    {
        for (i = 0; i < NEFF(l2); i++)
        {
            ELMT(temp, i) = ELMT(l1, i) - ELMT(l2, i);
        }
        return temp;
    }
}

boolean isListEqual(ListDin l1, ListDin l2)
{
    if (NEFF(l1) == NEFF(l2))
    {
        int i;
        for (i = 0; i < NEFF(l1); i++)
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

IdxType indexOf(ListDin l, ElType val)
{
    int i;
    for (i = 0; i < NEFF(l); i++)
    {
        if (ELMT(l, i) == val)
        {
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListDin l, ElType *max, ElType *min)
{
    int i;
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for (i = 1; i < NEFF(l); i++)
    {
        if (*max < ELMT(l, i))
        {
            *max = ELMT(l, i);
        }
        if (*min > ELMT(l, i))
        {
            *min = ELMT(l, i);
        }
    }
}
void copyList(ListDin lIn, ListDin *lOut)
{
    int i;
    dealocateList(lOut);
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i = 0; i < NEFF(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

ElType sumList(ListDin l)
{
    int i;
    ElType sum = 0;
    for (i = 0; i < NEFF(l); i++)
    {
        sum += ELMT(l, i);
    }
    return sum;
}

int countVal(ListDin l, ElType val)
{
    int i, sum = 0;
    for (i = 0; i < NEFF(l); i++)
    {
        if (ELMT(l, i) == val)
        {
            sum += 1;
        }
    }
    return sum;
}

void sort(ListDin *l, boolean asc)
{
    int i, j, swapped, temp;
    if (asc)
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

void insertLast(ListDin *l, ElType val)
{
    ELMT(*l, listLength(*l)) = val;
    NEFF(*l) += 1;
}

void deleteLast(ListDin *l, ElType *val)
{
    *val = ELMT(*l, listLength(*l) - 1);
    NEFF(*l) -= 1;
}

void expandList(ListDin *l, int num)
{
    ListDin temp;
    CreateListDin(&temp, CAPACITY(*l) + num);
    CAPACITY(*l) += num;
    copyList(*l, &temp);
    free(BUFFER(*l));
    BUFFER(*l) = (ElType *)malloc(CAPACITY(temp) * sizeof(ElType));
    copyList(temp, l);
    dealocateList(&temp);
}

void shrinkList(ListDin *l, int num)
{
    ListDin temp;
    CreateListDin(&temp, CAPACITY(*l) - num);
    CAPACITY(*l) -= num;
    copyList(*l, &temp);
    dealocateList(l);
    CreateListDin(l, CAPACITY(temp));
    copyList(temp, l);
    dealocateList(&temp);
}

void compressList(ListDin *l)
{
    shrinkList(l, CAPACITY(*l) - NEFF(*l));
}