#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <limits.h>
char *itobs(int n, char *str)
{
    int size = CHAR_BIT * sizeof(int);
    for (int i = size - 1; i >= 0; i--, n >>= 1)
    {
        str[i] = (1 & n) + '0';
    }
    str[size] = '\0';
    return str;
}
void show_bstr(const char *str)
{
    int i = 0;
    while (*str != '\0')
    {
        putchar(*str++);
        i++;
        if (i % 4 == 0)
            putchar(' ');
    }
    puts("");
}
void func_1()
{
    int num[4] = {3, 13, 59, 119};
    char str[CHAR_BIT * sizeof(int) + 1] = {};
    for (int i = 0; i < 4; i++)
    {
        printf("%d 2 base is:\n", num[i]);
        show_bstr(itobs(num[i], str));
    }
}
int f_2to10(char *str)
{
    int base = 1;
    int result = 0;
    int len = strlen(str);

    for (int i = len - 1; i >= 0; i--)
    {
        int num = (str[i] == '0' ? 0 : 1);
        result += base * num;
        base *= 2;
    }
    printf("%s is 10 base numer:%d\n", str, result);
    return result;
}
char *f_2to8(char *str, char *oct_str)
{
    int len = strlen(str);
    int oct_len = len / 3 + 1;
    if (len % 3 != 0)
    {
        oct_len++;
    }
    memset(oct_str, 0, 10);
    int oct_index = oct_len - 1;
    oct_str[oct_index] = '\0';
    oct_index--;
    for (int i = len - 1; i >= 0; i -= 3)
    {
        int val = 0;
        int base = 1;
        for (int j = i; i - j < 3 && j >= 0; j--)
        {
            val += base * (str[j] - '0');
            base *= 2;
        }
        oct_str[oct_index--] = val + '0';
    }
    printf("%s(2) = %s (8)\n", str, oct_str);
    return oct_str;
}
char *f_2to16(const char *str, char *hex_str)
{
    int len = strlen(str);
    int hex_len = (len + 3) / 4;
    int hex_index = hex_len - 1;
    memset(hex_str, 0, 10);
    for (int i = len - 1; i >= 0; i -= 4)
    {
        int val = 0;
        int base = 1;
        for (int j = i; i - j < 4 && j >= 0; j--)
        {
            val += base * (str[j] - '0');
            base *= 2;
        }
        char hex_char = val + '0';
        if (val > 9)
        {
            hex_char = val - 9 + 'a';
        }
        hex_str[hex_index--] = hex_char;
    }
    printf("%s(2) = %s(16)\n", str, hex_str);
    return hex_str;
}
void func_2()
{
    char *str[4] = {"00010101", "01010101", "01001100", "10011101"};
    for (int i = 0; i < 4; i++)
    {
        // to 10
        f_2to10(str[i]);
        // to 8
        char *oct_str = malloc(10 * sizeof(char));
        f_2to8(str[i], oct_str);
        f_2to16(str[i], oct_str);
    }
    // to 8
    // to 16
}
void func_3_4()
{
    //~3 =1111 1100=252 或者-4
    char ch=3;
    printf("~3 =%d\n",~ch);
    // 3&6= 011 & 110=010=2(10)
    printf("3&6 = %d\n",3&6);
    // 3|6 011 | 110 = 111 =7
    printf("3|6 = %d\n",3|6);
    //1|6 001 | 110=111=7
    printf("1|6 = %d\n",1|6);
    //3^6 011| 110=101=5 
    printf("3^6 = %d\n",3^6);
    //7>>1 ->111>>1 ->11=3
    printf("7>>1 = %d\n",7>>1);
    //7<<2 ->111<<2 ->11100=4+8+16=28
    printf("7<<2 = %d\n",7<<2);
}
int main(int argc, char *argv[])
{
    func_3_4();

    return 0;
}