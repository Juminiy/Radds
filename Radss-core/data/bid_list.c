#include "bid_list.h"
#include <malloc.h>
#include "mem_manager.h"


bidList* makeBidList()
{
    bidList *bid_list;
    if ((bid_list = malloc(sizeof(*bid_list))) == NULL){
        return NULL;
    }
    bid_list->head = bid_list->tail = NULL;
    bid_list->length = SIZE_ZERO;
    return bid_list;
}

void removeBidListNodes(bidList *bid_list)
{
    _size_t_ length;
    bidListNode *current, *next;

    current = bid_list->head;
    length = bid_list->length;
    while(length--) {
        next = current->next;
        if (bid_list->free_function_pointer) bid_list->free_function_pointer(current->data);
        mem_free(current);
        current = next;
    }
    bid_list->head = bid_list->tail = NULL;
    bid_list->length = SIZE_ZERO;
}

void deleteBidList(bidList *bid_list) 
{
    removeBidListNodes(bid_list);
    mem_free(bid_list);
}

void addBidListNodeHead(bidList *bid_list, bidListNode *bid_list_node)
{
    if (bid_list->length == SIZE_ZERO) {
        bid_list->head = bid_list->tail = bid_list_node;
        bid_list_node->prev = bid_list_node->next = NULL;
    } else {
        bid_list_node->prev = NULL;
        bid_list_node->next = bid_list->head;
        bid_list->head->prev = bid_list_node;
        bid_list->head = bid_list_node;
    }
    bid_list->length++;
}

void addBidListNodeTail(bidList *bid_list, bidListNode *bid_list_node)
{
    
}
