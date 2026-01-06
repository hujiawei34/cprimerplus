// convert fathoms to feet
#include <stdio.h>
int main(void)
{
    int fathoms;
    int feet;
    fathoms = 3;
    feet = 6 * fathoms;
    printf("There are %d feet in %d fathoms!\n", feet, fathoms);
    printf("Yes, I said %d feet!\n", 6 * fathoms);
    return 0;
}