#include "bid_list.h"
#include <malloc.h>
#include "mem_manager.h"

/// @brief create a bidirectional list
/// @return 
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

/// @brief remove bid_list's all nodes
/// @param bid_list 
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

/// @brief remove bid_list's all nodes and remove bid_list itself
/// @param bid_list 
void deleteBidList(bidList *bid_list) 
{
    removeBidListNodes(bid_list);
    mem_free(bid_list);
}

/// @brief add a node to bid_list front
/// @param bid_list 
/// @param bid_list_node 
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

/// @brief add a data to bid_list front
/// @param bid_list 
/// @param data 
/// @return 
bidList *addToBidListHead(bidList *bid_list, void *data)
{
    bidListNode *bid_list_node;

    if( (bid_list_node = malloc(sizeof(*bid_list_node))) == NULL)
        return NULL;
    bid_list_node->data = data;
    addBidListNodeHead(bid_list, bid_list_node);
    return bid_list;
}

/// @brief add a node to bid_list tail
/// @param bid_list 
/// @param bid_list_node 
void addBidListNodeTail(bidList *bid_list, bidListNode *bid_list_node)
{
    if (bid_list->length == SIZE_ZERO) {
        bid_list->head = bid_list->tail = bid_list_node;
        bid_list_node->prev = bid_list_node->next = NULL;
    } else {
        bid_list_node->prev = bid_list->tail;
        bid_list_node->next = NULL;
        bid_list->tail->next = bid_list_node;
        bid_list->tail = bid_list_node;
    }
    bid_list->length++;
}

/// @brief add a data to bid_list tail
/// @param bid_list 
/// @param data 
/// @return 
bidList *addToBidListTail(bidList *bid_list, void *data)
{
    bidListNode *bid_list_node;

    if( (bid_list_node = malloc(sizeof(*bid_list_node))) == NULL)
        return NULL;
    bid_list_node->data = data;
    addBidListNodeTail(bid_list, bid_list_node);
    return bid_list;
}

/// @brief insert a data to bid_list from direction
/// @param bid_list 
/// @param old_node 
/// @param data 
/// @param direction 
/// @return 
bidList *insertToBidList(bidList *bid_list, bidListNode *old_node, void *data, int direction)
{
    bidListNode *bid_list_node;
    if( (bid_list_node = malloc(sizeof(*bid_list_node))) == NULL)
        return NULL;
    bid_list_node->data = data;
    
    if(direction){
        bid_list_node->prev = old_node;
        bid_list_node->next = old_node->next;
        if (bid_list->tail == old_node){
            bid_list->tail = bid_list_node;
        }
    } else{
        bid_list_node->next = old_node;
        bid_list_node->prev = old_node->prev;
        if (bid_list->head == old_node){
            bid_list->head = bid_list_node;
        }
    }

    if(bid_list_node->prev) {
        bid_list_node->prev->next = bid_list_node;
    }
    if(bid_list_node->next) {
        bid_list_node->next->prev = bid_list_node;
    }
    bid_list->length++;

    return bid_list;
}

/// @brief remove a node from the bid_list
/// @param bid_list 
/// @param bid_list_node 
void UnLinkBidListNode(bidList *bid_list, bidListNode *bid_list_node)
{ 
    if(bid_list_node->prev)
        bid_list_node->prev->next = bid_list_node->next;
    else 
        bid_list->head = bid_list_node->next;
    if(bid_list_node->next)
        bid_list_node->next->prev = bid_list_node->prev;
    else
        bid_list->tail = bid_list_node->prev;
    bid_list_node->next = NULL;
    bid_list_node->prev = NULL;

    bid_list->length--;
}

/// @brief remove a node's data and remove node itself from bid_list
/// @param bid_list 
/// @param bid_list_node 
void removeFromBidList(bidList *bid_list, bidListNode *bid_list_node)
{
    UnLinkBidListNode(bid_list, bid_list_node);
    if(bid_list->free_function_pointer) bid_list->free_function_pointer(bid_list_node->data);
    mem_free(bid_list_node);
}

bidList *duplicateBidList(bidList *origin_list)
{
    
}

bidListNode *searchDataBidList(bidList *bid_list, void *data)
{

}

bidListNode *indexOfBidList(bidList *bid_list, _size_t_ index)
{

}

void rotateTailToHead(bidList *bid_list)
{

}

void rotateHeadToTail(bidList *bid_list)
{

}

void joinToBidList(bidList *dst, bidList *src)
{

}

void initBiListNode(bidList *bid_list, void *data)
{

}