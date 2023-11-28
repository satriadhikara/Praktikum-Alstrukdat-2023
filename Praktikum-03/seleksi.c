#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "listdin.h"

int main(){
    int n, m, i;
    ListDin l;
    scanf("%d", &n);
    scanf("%d", &m);
    CreateListDin(&l, n);
    for (i = 0; i < m; i++){
        int q;
        scanf("%d", &q);
        if (q == 1){
            int x, temp;
            scanf("%d", &x);
            int j = NEFF(l) - 1;
            sort(&l, false);
            if (NEFF(l) != 0){
                while (ELMT(l, j) < x){
                deleteLast(&l, &temp);
                j -= 1;
                }
            }
            
            insertLast(&l, x);
        }
        else if (q == 2){
            printf("%d\n", NEFF(l));
            printList(l);
            printf("\n");
        }
    }
    return 0;
}