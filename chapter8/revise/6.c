#include <stdio.h>
void func_a(void)
{
    int ch;
    while ((ch = getchar()) != 'i')
        putchar(ch);
}
void func_b(void)
{
    int ch;
    while((ch=getchar())!= '\n')
    {
        putchar(ch++);
        putchar(++ch);
    }
}
int main(void)
{
    // func_a();
    func_b();
    return 0;
}