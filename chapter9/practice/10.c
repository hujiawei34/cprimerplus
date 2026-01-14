#include <stdio.h>
void to_base_n(int a, int b)
{
    if (a >= b)
    {
        to_base_n(a / b, b);
    }
    printf("%d", a % b);
}
int main(void)
{
    to_base_n(7, 8);
    putchar('\n');
    to_base_n(16, 9);
    putchar('\n');

    return 0;
}