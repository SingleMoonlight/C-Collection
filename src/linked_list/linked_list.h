/**
 * Implementation of Bidirectional Linked List.
 * 
 * The bidirectional linked list implemented is shown in the following
 * figure.
 * 
 * HEAD <-> NODE <-> NODE <-> NODE ... <-> NODE
 *  ^                                       ^
 *  |---------------------------------------|
 * 
 * The header node does not store actual data and is only used as a
 * dummy node.
 * 
 * Create Date: 2023/4/18
 * Author: SingleMoonlight
*/
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

/* Node of a linked list */
typedef struct linked_list_node
{
    struct linked_list_node *next;      /* Pointer to the next node in the list */
    struct linked_list_node *prev;      /* Pointer to the previous node in the list */
} LINKED_LIST_NODE;

/* Linked list */
typedef struct linked_list
{
    LINKED_LIST_NODE node;  /* Head list node */
    int count;              /* Number of nodes in list */
} LINKED_LIST;

/**
 * Initialize a linked list.
 * 
 * @param list Pointer to the list to be initialize
 * @return N/A
 */
void linked_list_init(LINKED_LIST *list);

/**
 * Free a linked list.
 * 
 * Free all linked list node space by free function. If you want to use this function
 * to release all the space in the linked list, you need to place the linked list node
 * structure first in the structure you define.
 * 
 * @param list Pointer to the list to be released
 * @return N/A
*/
void linked_list_free(LINKED_LIST *list);

/**
 * Free a linked list by specified function.
 * 
 * You can use a custom release function to release the linked list.
 * 
 * @param list Pointer to the list to be released
 * @param func_free Pointer to the specified free function
 * @return N/A
*/
void linked_list_free_safe(LINKED_LIST *list, void (*func_free)(void *));

/**
 * Add a node to the end of the linked list.
 * 
 * @param list Pointer to the linked list where the node will be added
 * @param node Pointer to the node which will be added to the linked list
 * @return N/A
*/
void linked_list_add(LINKED_LIST *list, LINKED_LIST_NODE *node);

/**
 * Insert a node to the the linked list.
 * 
 * If the specified precursor node does not exist, the new node
 * will be inserted into the head of the linked list.
 * 
 * @param list Pointer to the linked list where the node will be inserted
 * @param prev_node Pointer to the previous node that will be inserted into the node
 * @param node Pointer to the node which will be inserted to the linked list
 * @return N/A
*/
void linked_list_insert(LINKED_LIST *list, LINKED_LIST_NODE *prev_node, LINKED_LIST_NODE *node);

/**
 * Delete a node from the linked list.
 * 
 * @param list Pointer to the linked list where the node will be deleted
 * @param node Pointer to the node which will be deleted
 * @return N/A
*/
void linked_list_delete(LINKED_LIST *list, LINKED_LIST_NODE *node);

/**
 * Concatenating a linked list to another linked list.
 * 
 * @param dst_list Pointer to the linked list where the added linked list will be concatenated
 * @param add_list Pointer to the added linked list
 * @return N/A
*/
void linked_list_concat(LINKED_LIST *dst_list, LINKED_LIST *add_list);

/**
 * Return the number of nodes in the linked list.
 * 
 * @param list Pointer to the linked list.
 * @return 0 if there is no node in the linked list
 *         n the number of nodes in the linked list
*/
int linked_list_count(LINKED_LIST *list);

/**
 * Determine whether the linked list is empty.
 * 
 * @param list Pointer to the linked list.
 * @return 0 if at least one node in the linked list
 *         1 if there is no node in the linked list
*/
int linked_list_is_empty(LINKED_LIST *list);

/**
 * Find the index of the specified node in the linked list.
 * 
 * @param list Pointer to the linked list.
 * @param node Pointer to the node to be searched for
 * @return -1 the specified node was not found
 *          n the index of the specified node to be searched for
*/
int linked_list_find(LINKED_LIST *list, LINKED_LIST_NODE *node);

LINKED_LIST_NODE *linked_list_first(LINKED_LIST *list);
LINKED_LIST_NODE *linked_list_last(LINKED_LIST *list);
LINKED_LIST_NODE *linked_list_nth(LINKED_LIST *list, int num);
LINKED_LIST_NODE *linked_list_next(LINKED_LIST_NODE *node);
LINKED_LIST_NODE *linked_list_prev(LINKED_LIST_NODE *node);
LINKED_LIST_NODE *linked_list_next_safe(LINKED_LIST_NODE *node);
LINKED_LIST_NODE *linked_list_prev_safe(LINKED_LIST_NODE *node);

#define LINKED_LIST_FOREACH(linked_list, node)  \
    for (node = linked_list_first(linked_list); \
        node != NULL;                           \
        node = linked_list_next_safe(node))



#endif /* __LINKED_LIST_H__ */
