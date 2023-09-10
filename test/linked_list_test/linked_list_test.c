#include <stdio.h>

#include "linked_list.h"
#include "linked_list_test.h"

static LINKED_LIST list;

void linked_list_test_main()
{
    printf("Linked list test main function\n");
    linked_list_init(&list);
}
