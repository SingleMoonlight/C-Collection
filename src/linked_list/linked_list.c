#include <stdlib.h>

#include "linked_list.h"

/* The head and tail node of the linked list that actually stores data */
#define HEAD node.next
#define TAIL node.prev

void linked_list_init(LINKED_LIST *list)
{
    /**
     * At the beginning, the first node and last node pointers of the linked list
     * is null.
    */
    list->HEAD = NULL;
    list->TAIL = NULL;

    list->count = 0;
}

void linked_list_free(LINKED_LIST *list)
{
    LINKED_LIST_NODE *node1 = NULL;
    LINKED_LIST_NODE *node2 = NULL;

    if (list->count > 0)
    {
        node1 = list->HEAD;
        while (node1 != NULL)
        {
            node2 = node1->next;
            free(node1);
            node1 = node2;
        }
        list->count = 0;
        list->HEAD = list->TAIL = NULL;
    }
}

void linked_list_free_safe(LINKED_LIST *list, void (*func_free)(void *))
{
    LINKED_LIST_NODE *node1 = NULL;
    LINKED_LIST_NODE *node2 = NULL;

    if (list->count > 0)
    {
        node1 = list->HEAD;
        while (node1 != NULL)
        {
            node2 = node1->next;
            func_free(node1);
            node1 = node2;
        }
        list->count = 0;
        list->HEAD = NULL;
        list->TAIL = NULL;
    }
}

void linked_list_add(LINKED_LIST *list, LINKED_LIST_NODE *node)
{
    linked_list_insert(list, list->TAIL, node);
}

void linked_list_insert(LINKED_LIST *list, LINKED_LIST_NODE *prev_node, LINKED_LIST_NODE *node)
{
    LINKED_LIST_NODE *next_node = NULL;

    if (prev_node == NULL)
    {
        next_node = list->HEAD;
        list->HEAD = node;
    }
    else
    {
        next_node = prev_node->next;
        prev_node->next = node;
    }

    if (next_node == NULL)
    {
        /* The specified precursor node happens to be the tail node of the linked list */
        list->TAIL = node;
    }
    else
    {
        next_node->prev = node;
    }

    node->next = next_node;
    node->prev = prev_node;
    list->count++;
}

void linked_list_delete(LINKED_LIST *list, LINKED_LIST_NODE *node)
{
    if (list->count == 0)
    {
        return;
    }

    if (linked_list_find(list, node) == -1)
    {
        return;
    }

    list->count--;

    if (node->next == NULL && node->prev == NULL)
    {
        list->HEAD = NULL;
        list->TAIL = NULL;
        return;
    }

    if (node->prev == NULL)
    {
        list->HEAD = node->next;
        node->next->prev = NULL;
    }
    else
    {
        node->prev->next = node->next;
    }

    if (node->next == NULL)
    {
        list->TAIL = node->prev;
        node->prev->next = NULL;
    }
    else
    {
        node->next->prev = node->prev;
    }

    node->next = NULL;
    node->prev = NULL;
}

void linked_list_concat(LINKED_LIST *dst_list, LINKED_LIST *add_list)
{
    if (add_list->count == 0)
    {
        return;
    }

    if (dst_list == 0)
    {
        *dst_list = *add_list;
    }
    else
    {
        dst_list->TAIL->next = add_list->HEAD;
        add_list->HEAD->prev = dst_list->TAIL;
        dst_list->TAIL = add_list->TAIL;

        dst_list->count += add_list->count;
    }

    linked_list_init(add_list);
}

int linked_list_count(LINKED_LIST *list)
{
    return list->count;
}

int linked_list_is_empty(LINKED_LIST *list)
{
    if (list->count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int linked_list_find(LINKED_LIST *list, LINKED_LIST_NODE *node)
{
    LINKED_LIST_NODE *next_node = NULL;
    int index = 0;

    next_node = linked_list_first(list);

    while ((next_node != NULL) && (next_node != node))
    {
        index++;
        next_node = linked_list_next(next_node);
    }

    if (next_node == NULL)
    {
        return -1;
    }
    else
    {
        return index;
    }
}

LINKED_LIST_NODE *linked_list_first(LINKED_LIST *list)
{
    return list->HEAD;
}

LINKED_LIST_NODE *linked_list_last(LINKED_LIST *list)
{
    return list->TAIL;
}

LINKED_LIST_NODE *linked_list_nth(LINKED_LIST *list, int num)
{
    LINKED_LIST_NODE *node = NULL;

    if(num < 1 || num > list->count)
    {
        return NULL;
    }

    if (num < (list->count >> 1))
    {
        node = list->HEAD;

        while (--num > 0)
        {
            node = node->next;
        }
    }
    else
    {
        num -= list->count;
        node = list->TAIL;

        while (num++ < 0)
        {
            node = node->prev;
        }
    }

    return node;
}

LINKED_LIST_NODE *linked_list_next(LINKED_LIST_NODE *node)
{
    return node->next;
}

LINKED_LIST_NODE *linked_list_prev(LINKED_LIST_NODE *node)
{
    return node->prev;
}

LINKED_LIST_NODE *linked_list_next_safe(LINKED_LIST_NODE *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    return node->next;
}

LINKED_LIST_NODE *linked_list_prev_safe(LINKED_LIST_NODE *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    return node->prev;
}
