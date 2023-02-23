/*
@author chisato-x
@time 2023.2.23
*/
#ifndef __BID_LIST_H__
#define __BID_LIST_H__
#include "defs.h"

typedef struct bidirectionalListNode {
    struct bidrectionalListNode *prev;
    struct bidrectionalListNode *next;
    void *data;
} bidListNode;

typedef struct bidrectionalList {
    bidListNode *head;
    bidListNode *tail;
    _size_t_ length;
    void (*free_function_pointer)(void *mem_pointer);
} bidList;



#endif 