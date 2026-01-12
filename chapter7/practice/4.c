#include <stdio.h>
void func_3(void)
{
    int rt = 0; // replace time
    char ch;
    while ((ch = getchar()) != '#')
    {
        if (ch == '.')
        {
            putchar('!');
            rt++;
        }
        else if (ch == '!')
        {
            putchar('!');
            putchar('!');
            rt++;
        }
        else
            putchar(ch);
    }
    printf("==========\n");
    printf("replace time:%d.\n", rt);
}
void func_4(void)
{
    /** rewrite func_3 using switch */
    int rt = 0; // replace time
    char ch;
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
        case '.':
            putchar('!');
            rt++;
            break;
        case '!':
            putchar('!');
            putchar('!');
            rt++;
        default:
            putchar(ch);
        }
    }
    printf("==========\n");
    printf("replace time:%d.\n", rt);
}
int main(void)
{
    // func_3();
    func_4();
    return 0;
}