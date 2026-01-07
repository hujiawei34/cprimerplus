#include <stdio.h>
int main(void)
{
    // a.
    printf("%15lu\n", 123456789L);

    // b.
    printf("%#4x\n", 0x8a);

    // c.
    printf("%-12.2E.\n", 233.0);

    // d.
    printf("%+10.3f\n", 232.346);

    // e.
    printf("%.8s\n","12345678901234567890");
    return 0;
}