#include <stdio.h>
/*
Hi Hi Hi  Bye! Bye! Bye! Bye! Bye! */
void func_a()
{
    int i = 0;
    while (++i < 4)
        printf("Hi! ");
    printf("%d===", i);
    do
    {
        printf("Bye! ");
        printf("%d", i);
    } while (i++ < 8);
}
/** will print
 * ACGM
 * 
 */
void func_b(void){
    int i;
    char ch;
    for(i=0,ch='A';i<4;i++,ch+=2*i){
        printf("%c",ch);
    }
}
int main(void)
{
    func_b();
    return 0;
}
