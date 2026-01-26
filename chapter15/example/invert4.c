#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <limits.h>
char *itobs(int, char *);
void show_bstr(const char *);
int invert_end(int num, int bits);

int main(int argc, char *argv[])
{
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    int number;

    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    while (scanf("%d", &number) == 1)
    {
        itobs(number, bin_str);
        printf("%d is\n", number);
        show_bstr(bin_str);
        puts("\n");
        number = invert_end(number, 4);
        printf("Inverting the last 4 bits gives\n");
        show_bstr(itobs(number, bin_str));
        puts("");
    }
    puts("Bye!");
    return 0;
}
char *itobs(int n, char *str)
{
    int size = CHAR_BIT * sizeof(int);

    for (int i = size - 1; i >= 0; i--, n >>= 1)
    {
        str[i] = (01 & n) + '0';
    }
    str[size] = '\0';
    return str;
}
void show_bstr(const char *str)
{
    int i = 1;
    while (*str != '\0')
    {
        printf("%c", *str);
        if (i % 4 == 0)
            putchar(' ');
        i++;
        str++;
    }
}
int invert_end(int num, int bits)
{
    int mask = 0;
    int bitval = 1;
    while (bits-- > 0)
    {
        mask |= bitval;
        bitval <<= 1;
    }
    return num ^ mask;
}