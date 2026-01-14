#include <stdio.h>
int main(void)
{
    int *ptr;                          // 步长int
    int fort[2][2] = {{12}, {14, 16}}; //{{12,0},{14,16}}
    ptr = fort[0];                     // 指向12，步长1 int
    //*ptr=12,*(ptr+2)=14
    printf("*ptr=%d,*(ptr+2)=%d\n", *ptr, *(ptr + 2));

    return 0;
}