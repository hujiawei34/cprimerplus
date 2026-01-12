#include <stdio.h>
#include <stdbool.h>
bool is_prime(int i)
{
    for (int n = 2; n < i/2 ; n++)
    {
        if (i % n == 0)
            return false;
    }
    return true;
}
int main(void)
{
    int i; // input
    printf("input a 正整数：");
    int status = scanf("%d", &i);
    while (status != 1 || i <= 0)
    {
        while (getchar() != '\n')
            ;
        printf("invalid number,input a 正整数：");
        status = scanf("%d", &i);
    }
    printf("all prime number <= %d is:\n",i);
    for (int index = i; index > 0; index--)
    {
        if(is_prime(index))
            printf("%d ",index);
    }
    printf("\n");

    return 0;
}