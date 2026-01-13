#include <stdio.h>
int main(void)
{
    int n = 0;
    while (getchar() != EOF)
        n++;
    printf("count of charaters:%d\n", n);
    /**
     * cd "/root/code/github/cprimerplus/chapter8/practice/" && gcc 3.c -o count.out && ./count.out <essay >essayct
     */
    return 0;
}