#include <stdio.h>
int main(void)
{
    char prev, ch;
    prev = '\0';
    int c = 0;
    while ((ch = getchar()) != '#')
    {
        if (ch == 'i')
        {
            if (prev == 'e')
                c++;
        }
        prev = ch;
    }
    printf("there are %d times of ei.\n", c);

    return 0;
}