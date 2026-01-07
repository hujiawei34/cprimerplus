#include <stdio.h>
#include <string.h>
int main(void)
{
    char first_name[30];
    char second_name[30];
    printf("Please enter your first name and second name: ");
    scanf("%s %s", first_name, second_name);
    // a.
    printf("===a==\n\"%s\" \"%s\"\n", second_name, first_name);

    // b.
    printf("===b==\n\"%20s\" \"%20s\"\n", second_name, first_name);

    // c.
    printf("===c==\n\"%-20s\" \"%-20s\"\n", second_name, first_name);

    // d.

    printf("===d==\n\"%*s\" \"%*s\"\n", (int)strlen(second_name) + 3, second_name, (int)strlen(first_name) + 3, first_name);
    return 0;
}