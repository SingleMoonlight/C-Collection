#include <stdio.h>
#include <stdlib.h>

#include "linked_list_test.h"

#define ARRAY_SIZE(array)  sizeof(array) / sizeof(array[0])
#define TEST_ITEM_NAME_MAX_LENGTH   32


typedef struct test_item
{
    char name[TEST_ITEM_NAME_MAX_LENGTH];
    void (*test_func)(void);
} TEST_ITEM;

static TEST_ITEM test_items[] =
{
    {
        .name = "All",
        .test_func = NULL
    },
    {
        .name = "Linked list",
        .test_func = linked_list_test_main
    }
};

int main()
{
    unsigned int i = 0;
    unsigned int test_item_index = 0;

    printf("A common collection library developed using C\n");
    printf("Project provides some default test cases, you can choose the items you want to test\n");
    printf("--------------------------------\n");

    for (i = 0; i < ARRAY_SIZE(test_items); i++)
    {
        printf("Index %d: %s\n", i, test_items[i].name);
    }
    printf("--------------------------------\n");
    printf("Please select a test item: ");
    scanf("%d", &test_item_index);

    printf("--------------------------------\n");
    if (test_item_index == 0)
    {
        for (i = 1; i < ARRAY_SIZE(test_items); i++)
        {
            test_items[i].test_func();
        }
    }
    else if (test_item_index > 0 && test_item_index < ARRAY_SIZE(test_items))
    {
        test_items[test_item_index].test_func();
    }
    else
    {
        printf("You chose an illegal test item\n");
    }

    return 0;
}
