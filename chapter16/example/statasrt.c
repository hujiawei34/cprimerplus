#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <limits.h>
_Static_assert(1,"16-bit char falsely assumed");
int main(int argc, char *argv[])
{
    puts("char is 16 bits.");

    return 0;
}