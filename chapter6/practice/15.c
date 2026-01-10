#include <stdio.h>
int main(void)
{
    const int SIZE = 256;
    char list[255];
    int i = 0;
    char current;
    int status = scanf("%c", &current);
    while (current != '\n')
    {
        list[i++] = current;
        status = scanf("%c", &current);
    }
    for (int j = sizeof list - 1; j >= 0; j--)
    {
        printf("%c", list[j]);
    }
    printf("\n");
    return 0;
}