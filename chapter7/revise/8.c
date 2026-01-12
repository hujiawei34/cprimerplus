/* retire.c */
#include <stdio.h>
int main(void)
{
    int age = 20;
    while (age++ <= 65)
    {
        if ((age % 20) == 0)
            printf("You are %d.Here is a raise.\n", age);
        if (age == 65)
            printf("You are %d.Here is your gold watch.\n", age);
    }
    /**
     * this will print:
     * You are 40.Here is a raise.
     * You are 60.Here is a raise.
     * You are 65.Here is your gold watch.
     */
    return 0;
}