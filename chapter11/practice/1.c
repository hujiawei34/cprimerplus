#include <stdio.h>

void get_input(char ar[],int n)
{
    fgets(ar,n,stdin);
}
int main(void)
{
    char str[100];
    get_input(str,100);
    // puts(str);
    printf("%s",str);
    return 0;
}