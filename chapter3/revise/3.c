#include<stdio.h>
#include<inttypes.h>
#include<limits.h>
int main(void)
{
    int32_t num1 = INT_MAX+1;
    printf("num1 (INT_MAX + 1) = %" PRId32 "\n", num1);
    return 0;
}