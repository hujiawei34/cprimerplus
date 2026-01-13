#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    fp = fopen("blank.c", "r");
    int n = 0;
    while (getc(fp) != EOF)
        n++;
    printf("blank.c has %d characters.\n", n);

    return 0;
}