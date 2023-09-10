#ifndef __TEST_H__
#define __TEST_H__

#define ARRAY_SIZE(array)  sizeof(array) / sizeof(array[0])
#define TEST_ITEM_NAME_MAX_LENGTH   32

#define TEST_CASE_PASS                  0
#define TEST_CASE_FAIL                  -1


typedef void (*TEST_MAIN_FUNC)(void);

typedef struct test_item
{
    char name[TEST_ITEM_NAME_MAX_LENGTH];
    TEST_MAIN_FUNC func;
} TEST_ITEM;


typedef struct test_case
{
    void *func;
    void *params;
    void *except;
    int result;
} TEST_CASE;


void test_main(void);

#endif /* __TEST_H__ */
