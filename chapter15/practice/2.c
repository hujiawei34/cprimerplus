#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <limits.h>
int bstoi(char *str)
{
    int len = strlen(str);
    int sum = 0;
    int base = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        sum += base * (str[i] - '0');
        base <<= 1;
    }
    return sum;
}
char *itobs(int n, char *str)
{
    int size = CHAR_BIT * sizeof(int);
    memset(str, 0, 10);
    for (int i = size - 1; i >= 0; i--)
    {
        str[i] = (1 & n) == 0 ? '0' : '1';
        n >>= 1;
    }
    str[size] = '\0';
    return str;
}
char *convert_bstr(const char *str, char *new_str)
{
    memset(new_str, 0, 10);
    bool start = false;
    int i = 0;
    while (*str != '\0')
    {
        if (*str == '0' && start == false)
        {
            str++;
            continue;
        }
        else if (*str == '1' && start == false)
        {
            start = true;
            new_str[i++] = *str;
            str++;
        }
        else
        {
            new_str[i++] = *str;
            str++;
        }
    }
    new_str[i] = '\0';
    return new_str;
}
void func1(char *s1, char *s2)
{
    int b1 = bstoi(s1);
    int b2 = bstoi(s2);
    int result = ~b1;
    char str[CHAR_BIT * sizeof(int) + 1];
    char new_str[CHAR_BIT * sizeof(int) + 1];
    itobs(result, str);
    convert_bstr(str, new_str);
    // printf("%s & %s = %s\n",s1,s2,new_str);
    printf("~%s =\n", s1);
    printf(" %s\n", new_str);

    result = ~b2;
    itobs(result, str);
    convert_bstr(str, new_str);
    printf("~%s =\n", s2);
    printf(" %s\n", new_str);
}
void func2(char *s1, char *s2)
{
    int b1 = bstoi(s1);
    int b2 = bstoi(s2);
    int result = b1 & b2;
    char str[CHAR_BIT * sizeof(int) + 1];
    char new_str[CHAR_BIT * sizeof(int) + 1];
    itobs(result, str);
    convert_bstr(str, new_str);
    // printf("%s & %s = %s\n",s1,s2,new_str);
    printf("%s &\n", s1);
    printf("%s =\n", s2);
    printf("%8s\n", new_str);
}
void func3(char *s1, char *s2)
{
    int b1 = bstoi(s1);
    int b2 = bstoi(s2);
    int result = b1 | b2;
    char str[CHAR_BIT * sizeof(int) + 1];
    char new_str[CHAR_BIT * sizeof(int) + 1];
    itobs(result, str);
    convert_bstr(str, new_str);
    // printf("%s & %s = %s\n",s1,s2,new_str);
    printf("%s |\n", s1);
    printf("%s =\n", s2);
    printf("%8s\n", new_str);
}
void func4(char *s1, char *s2)
{
    int b1 = bstoi(s1);
    int b2 = bstoi(s2);
    int result = b1 ^ b2;
    char str[CHAR_BIT * sizeof(int) + 1];
    char new_str[CHAR_BIT * sizeof(int) + 1];
    itobs(result, str);
    convert_bstr(str, new_str);
    // printf("%s & %s = %s\n",s1,s2,new_str);
    printf("%s ^\n", s1);
    printf("%s =\n", s2);
    printf("%8s\n", new_str);
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        puts("Usage: %s <bin_string1> <bin_string2>");
        exit(1);
    }
    char *b1 = argv[1];
    char *b2 = argv[2];
    // char *b1 = "00010101";
    // char *b2 = "01010101";

    printf("%s(2) = %d(10)\n", b1, bstoi(b1));
    printf("%s(2) = %d(10)\n", b2, bstoi(b2));
    // int n=85;
    // char str[CHAR_BIT * sizeof(int)];
    // itobs(n, str);
    // char *new_str=calloc(sizeof(char),CHAR_BIT*sizeof(int));

    // convert_bstr(str,new_str);
    // printf("%d(10) =%s(2)\n", n, new_str);

    func1(b1, b2);
    func2(b1,b2);
    func3(b1,b2);
    func4(b1,b2);


    //~ & | ^
    return 0;
}