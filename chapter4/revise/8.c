#include <stdio.h>
int main(void)
{
    //a.
    printf("%6d\n", 1234);

    //b.
    printf("%#*o\n", 4, 112);

    //c.
    printf("==%2c==\n", 'A');

    //d.
    printf("%+g\n",3.134);

    //e.
    printf("===%-7.5s===\n","12345678901234567890");
    return 0;
}