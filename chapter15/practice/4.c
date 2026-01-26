#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
int get_bit_value(int n,int bit)
{
    bit--;
    while(bit-->0)
    {
        n>>=1;
    }
    return 1&n;
}
int main(int argc, char *argv[])
{
    int n=8;
    int bit=6;
    printf("%d location %d is %d\n",n,bit,get_bit_value(n,bit));

    return 0;
}