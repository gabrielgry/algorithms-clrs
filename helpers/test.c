#include <stdio.h>
#include <stdbool.h>
#include "test.h"

void test_print_result(bool pass, char message[])
{
    char *status = pass ? "\x1b[32mPASS\x1b[0m" : "\x1b[31mFAILED\x1b[0m";
    
    printf("[%s] %s\n", status, message);
}
