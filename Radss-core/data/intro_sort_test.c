#include "intro_sort.h"
#include <stdlib.h>
#include <stdio.h>

int cmp(const void *a, const void *b){
    int *int_a = (int *)a;
    int *int_b = (int *)b;
    return *int_a - *int_b;
}

void swapSeqPointerTest(){

    int seq1[10] = {1, 2, 3, 4, 5, 6};
    int seq2[10] = {7, 8, 9, 10, 11, 12};
    
    // swapSeqPointer(int, &seq1, &seq2, 6)
    swapPairPointer(seq1, seq2);

    for(int i=0;i<6;i++){
        printf("seq1 = %d, seq2 = %d\n",seq1[i],seq2[i]);
    }
}



int main(){

    int a[10] = {9, 1, 2, 0, 5, 3, 4, 7, -1, -11};

    // intro_sort(a, 10, sizeof(int), cmp, 0, 10);

    qsort(a, 10, sizeof(int), cmp);

    // for(int i=0;i<10;i++){
    //     printf("%d,",a[i]);
    // }
    // printf("\n");

    swapSeqPointerTest();

    return 0;
}