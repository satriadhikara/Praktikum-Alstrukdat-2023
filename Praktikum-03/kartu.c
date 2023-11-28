#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "listdin.h"

int main(){
    int n, m, x = 0, y = 0, i, temp;
    ListDin l1, l2, l3;
    CreateListDin(&l1, 100000);
    CreateListDin(&l2, 100000);
    CreateListDin(&l3, 100000 * 2);
    readList(&l1);
    readList(&l2);
    int len1 = NEFF(l1);
    int len2 = NEFF(l2);
    while (len1 != 0 || len2 != 0){
        if (len1 == 0){
            temp = ELMT(l2, y);
            insertLast(&l3, temp);
            y += 1;
            len2 -= 1;
        }
        else if (len2 == 0){
            temp = ELMT(l1, x);
            insertLast(&l3, temp);
            x += 1;
            len1 -= 1;
        }
        else if (ELMT(l1, x) >= ELMT(l2, y)){
            temp = ELMT(l1, x);
            insertLast(&l3, temp);
            x += 1;
            len1 -= 1;
        }
        else if (ELMT(l1, x) < ELMT(l2, y)){
            temp = ELMT(l2, y);
            insertLast(&l3, temp);
            y += 1;
            len2 -= 1;
        }
    }
    printList(l3);
    printf("\n");
    return 0;
}