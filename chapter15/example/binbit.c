/** 使用位操作显示二进制 */
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <limits.h>
char *itobs(int, char *);
void show_bstr(const char *);
int main(int argc, char *argv[])
{
    char bin_str[CHAR_BIT * sizeof(int) + 1];//char_bit=bytes has how many bit, sizeof(int) return int bytes,so this is how many  bit int has
    int number;

    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    while (scanf("%d", &number) == 1)
    {
        printf("%d in 2 base is :", number);
        itobs(number, bin_str);
        show_bstr(bin_str);
        puts("");
    }
    puts("Bye!");
    return 0;
}
char *itobs(int n, char *str)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for (i = size - 1; i >= 0; i--, n >>= 1)
    {
        str[i] = (01 & n) + '0';
    }
    str[size] = '\0';
    return str;
}
void show_bstr(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        putchar(str[i]);
        i++;
        if (i % 4 == 0 && str[i])
            putchar(' ');
    }
}
