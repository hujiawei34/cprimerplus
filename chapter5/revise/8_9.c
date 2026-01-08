#include <stdio.h>
#define TEN 10
int main(void)
{
    int n='a'-1;
    while(n++<'g'){
        printf("%c\n",n);
    }
    printf("\n");

    return 0;
}