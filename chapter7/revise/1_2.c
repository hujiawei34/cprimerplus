#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
void func_1(void)
{
    // a.
    // true && false =false
    bool result = 100 > 3 && 'a' > 'c';
    printf("result=%d,expect 0\n", result);

    // b.
    result = 100 > 3 || 'a' > 'c'; // true || flase =true =1
    printf("result=%d,expect 1\n", result);

    // c.
    result = !(100 > 3); //! true=false =0
    printf("result=%d,expect 0 \n", result);
}
void func_2(void)
{
    // a.
    int number = 99;
    if (number >= 90 && number < 100)
        printf("true");
    // b.
    char ch;
    ch = 's';
    if (ch != 'q' && ch != 'k')
        printf("true");

    // c.
    number = 9;
    if (number >= 1 && number <= 9 && number != 5)
        printf("true");

    // d.
    number = 10;
    if (number < 1 || number > 9)
        printf("true");
}
int main(void)
{
    // func_1();
    func_2();

    return 0;
}