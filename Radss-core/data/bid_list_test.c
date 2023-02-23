#include "bid_list.h"
#include "defs.h"
#include <stdio.h>

int main(){

    printf("u long long %d, u long %d\n",sizeof(_uint_64_) ,sizeof(_uint_32_));
    printf("long long %d, long %d\n",sizeof(_int_64_) ,sizeof(_int_32_));
    printf("u char %d, char%d\n",sizeof(_uint_8_) ,sizeof(_int_8_));
    return 0;
}