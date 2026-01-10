#include <stdio.h>
#include <string.h>
int main(void)
{
    printf("input a word:");
    char words[40];
    scanf("%s", words);
    for (int i = strlen(words); i >= 0; i--)
    {
        printf("%c", words[i]);
    }
    printf("\n");
    return 0;
}