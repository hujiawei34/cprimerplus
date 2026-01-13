#include <stdio.h>
#include "9.h"
void print_choice()
{
    printf("%s\n", PROMPT1);
    printf("1) %s\t2)%s\n", OPTION_NAME1, OPTION_NAME2);
    printf("3) %s\t4) quit\n", OPTION_NAME3);
    printf("%s\n", PROMPT2);
}
int get_choice(int c, int f)
{
    int i;
    int status = scanf("%d", &i);
    while(getchar()!='\n');
    while (status != 1 || (i < c || i > f))
    {
        if (status != 1)
            return 4;
        print_choice();
        status = scanf("%d", &i);
    }
    return i;
}