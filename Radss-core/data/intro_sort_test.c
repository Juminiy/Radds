#include "intro_sort.h"
#include <stdio.h>

_bool_ cmp(const void *a, const void *b){
    int *int_a = (int *)a;
    int *int_b = (int *)b;
    return *int_a < *int_b;
}

int main(){

    int a[10] = {9, 1, 2, 0, 5, 3, 4, 7, -1, -11};

    intro_sort(a, 10, sizeof(int), cmp, 0, 10);

    for(int i=0;i<10;i++){
        printf("%d,",a[i]);
    }
    return 0;
}