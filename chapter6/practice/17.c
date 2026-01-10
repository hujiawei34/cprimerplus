#include <stdio.h>
int main(void)
{
    double origin = 1000000;
    const double rate = 1.08;
    double left;
    int year = 0;
    left = origin;
    printf("year left\n");
    printf("%4d %4.2f\n", year, left);
    for (year = 1; left > 0; year++)
    {
        left *= rate;
        left -= 100000;
        printf("%4d %4.2f\n", year, left);
    }
    return 0;
}