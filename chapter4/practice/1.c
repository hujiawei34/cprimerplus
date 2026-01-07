#include <stdio.h>
int main(void)
{
    char first_name[30];
    char second_name[30];
    printf("Please enter your first name and second name: ");
    scanf("%s %s", first_name, second_name);
    printf("Hello, %s,%s!\n", second_name, first_name);
    return 0;
}