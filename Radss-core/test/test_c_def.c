#include <stdint.h>
#include <stdio.h>

#define swapPairPointer(a, b)                                           \
    if(type == 0) {                                                     \
        _uint_32_ t = *(_uint_32_ *) (void *)(a);                       \
        *(_uint_32_ *)(void *)(a) = *(_uint_32_ *)(void *)(b);          \
        *(_uint_32_ *)(void *)(b) = t;                                  \
    } else                                                              \
        swapSequence(a, b, es, type) 


#define SwapSequencePointer(TYPE, seq1, seq2, n) {  \
    uint32_t index = (n)/ sizeof(TYPE);             \
    TYPE *pi = (TYPE *)(void *)(seq1);              \
    TYPE *pj = (TYPE *)(void *)(seq2);              \
    do{                                             \
        TYPE t = *seq1;                             \
        *seq1++ = *seq2;                            \
        *seq2++ = t;                                \
    }while(--index > 0);                            \
}

void swapSequence(uint8_t *seq1, uint8_t *seq2, size_t n, int type){
    if(type <= 1)
        SwapSequencePointer(uint32_t, seq1, seq2, n)
    else
        SwapSequencePointer(uint8_t, seq1, seq2, n)
}



int main(){

    int arr1[10] = {1, 2, 3, 4, 5, 6};
    int arr2[10] = {7, 8, 9, 10, 11, 12};
    swapSequence(arr1, arr2, 6*sizeof(int), 1);

    for(int i=0;i<6;i++){
        printf("%d ", arr1[i]);
    }

    return 0;
}