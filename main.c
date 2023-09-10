#include <stdio.h>
#include <stdlib.h>

#include "test.h"

int main()
{
    char choose = '0';

    printf("A common collection library developed using C\n\n");
    printf("This project provides some default test cases. Do you want to run these test cases? (Y/N): ");

    scanf("%c", &choose);
    if (choose == 'y' || choose == 'Y')
    {
        test_main();
    }
    else
    {
        printf("Exit.\n");
    }

    return 0;
}
