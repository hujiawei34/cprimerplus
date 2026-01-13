#include <stdio.h>
char get_first(){
    char ch=getchar();
    while(getchar() !='\n');
    return ch;
}
int main(void)
{
    printf("input anything:");
    char ch=get_first();
    printf("%c\n",ch);

    return 0;
}