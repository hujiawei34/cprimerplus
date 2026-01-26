#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
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
int main(int argc, char *argv[])
{
    char *pbin="01001001";//1+8+64
    printf("%s = %d\n",pbin,f_2to10(pbin));

    return 0;
}