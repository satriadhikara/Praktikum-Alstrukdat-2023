#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "listdin.h"

int main(){
    ListDin l;
    int max, min, sum = 0;
    CreateListDin(&l, 100);
    readList(&l);
    if (NEFF(l) < 2){
        printf("%d\n", sum);
    }
    else{
        extremeValues(l, &max, &min);
        sum = (max + 1) - min;
        printf("%d\n", sum);
    }
    return 0;
}