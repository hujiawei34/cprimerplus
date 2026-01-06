/** charcode.c -- 显示字符的ASCII码 */
#include <stdio.h>
int main(void)
{
    char ch;
    printf("Please enter a character: ");

    scanf("%c", &ch);
    printf("The ASCII code for %c is %d.\n", ch, ch);
    
    return 0;
}