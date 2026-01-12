#include <stdio.h>
int main(void)
{
    char ch;
    int n = 0;
    while ((ch = getchar()) != '#')
    {

        printf("%c=%d",ch,ch);
        if (++n % 8 == 0)
            printf("\n");
        else
            printf(",");
    }
    return 0;
}