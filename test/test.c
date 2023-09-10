#include <stdio.h>
#include <stdlib.h>

#include "test.h"

#include "linked_list_test.h"

static TEST_ITEM test_items[] =
{
    {
        .name = "Linked list",
        .func = linked_list_test_main
    }
};

void test_main(void)
{
    unsigned int i = 0;

    printf("================================\n");
    for (i = 0; i < ARRAY_SIZE(test_items); i++)
    {
        printf("Run the test cases of %s\n", test_items[i].name);
        test_items[i].func();
        printf("%s test case run completed\n", test_items[i].name);
    }
    printf("================================\n");
}
