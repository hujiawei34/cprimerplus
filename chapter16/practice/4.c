#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
void delay(double sec)
{
    clock_t begin = clock();
    double time = ((double)(clock() - begin)) / CLOCKS_PER_SEC;
    while (time < sec)
    {
        time = ((double)(clock() - begin)) / CLOCKS_PER_SEC;
    }
}
int main(int argc, char *argv[])
{
    clock_t t1 = clock();
    clock_t t2 = clock();
    printf("t1=%ld ,t2=%ld,CLOCKS_PER_SEC=%ld\n", t1, t2, CLOCKS_PER_SEC);
    clock_t begin = clock();
    printf("start,t=%ld\n", begin);
    delay(0.13);
    clock_t end = clock();
    printf("current t=%ld,time=%g\n", end, ((double)(end - begin)) / CLOCKS_PER_SEC);

    return 0;
}