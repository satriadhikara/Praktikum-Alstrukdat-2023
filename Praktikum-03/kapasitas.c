#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "listdin.h"

int main(){
    ListDin l;
    int i, n, temp;
    CreateListDin(&l, 0);
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        int tipe;
        scanf("%d",&tipe);
        if(tipe==1){

            int x;

            scanf("%d",&x);

            // proses query tipe 1
            if (isEmpty(l)){
                expandList(&l, 1);
            }
            else if (isFull(l)){
                if (CAPACITY(l) == 1){
                    expandList(&l, 1);
                }
                else{
                    expandList(&l, CAPACITY(l));
                }
            }
            insertLast(&l, x);


        }else if(tipe==2){

            // proses query tipe 2
            deleteLast(&l, &temp);
            if (NEFF(l) == 0){
                CAPACITY(l) = 0;
            }
            else if (NEFF(l) <= round(CAPACITY(l) / 2)){
                shrinkList(&l, round(CAPACITY(l) / 2));
            }

        }else{

            // proses query tipe 3
            printf("%d ", CAPACITY(l));
            printList(l);
            printf("\n");
        }
    }
    return 0;
}