#include <stdio.h>
#include <string.h>
int main(void)
{
    printf("enter your first name: ");
    char first_name[30];
    scanf("%s", first_name);
    printf("enter your last name: ");
    char last_name[30];
    scanf("%s", last_name);

    int fn_len=strlen(first_name);
    int ln_len=strlen(last_name);

    printf("%s %s\n", last_name, first_name);
    printf("%*d %*d\n", ln_len, ln_len, fn_len, fn_len);

    printf("%s %s\n", last_name, first_name);
    printf("%-*d %-*d\n", ln_len , ln_len, fn_len, fn_len);
    return 0;
}