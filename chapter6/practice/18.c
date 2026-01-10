#include <stdio.h>
int main(void)
{
    int wn = 0;         // weak number
    int fn = 5;         // frient number
    const int dn = 150; // dunbar's number
    printf("week no. friend numbers\n");
    printf("%-8d %-14d\n", wn, fn);
    for (wn = 1; fn <= dn; wn++)
    {
        fn -= wn;
        fn *= 2;
        printf("%-8d %-14d\n", wn, fn);
    }
    return 0;
}