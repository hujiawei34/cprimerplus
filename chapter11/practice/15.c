#include <stdio.h>
#include <ctype.h>
#include "my.h"
int myatoi(char *str)
{
    int re = 0;
    int base;
    char *p2 = str;
    int is_pure = 1;
    while (*p2)
    {
        if (!isdigit(*p2))
        {
            is_pure = 0;
            break;
        }
        p2++;
    }
    if (!is_pure)
    {
        return 0;
    }
    for (p2--, base = 1; p2 >= str; p2--)
    {
        re += (*p2 - '0') * base;
        base *= 10;
    }
    return re;
}
int main(void)
{
    while(1){
        char line[100];
        s_gets(line,100);
        printf("%d\n", myatoi(line));
    }
    return 0;
}