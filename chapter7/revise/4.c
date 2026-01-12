#include <stdio.h>
int main(void)
{
    // a.
    printf("5>2 expect 1,result is %d\n", 5 > 2);

    // b.
    printf("3+4 >2 && 3< 2 expect 0,result is %d\n", 3 + 4 > 2 && 3 < 2);

    // c.
    int x, y;
    printf("x>=y || y> x expect 1,result is %d \n", x >= y || y > x);

    // d.
    int d;
    printf("d=5+(6>2) expect 6,result is %d\n", d = 5 + (6 > 2));

    // e.
    printf("'X' > 'T' ?10:5 expect 10,result is %d\n", 'X' > 'T' ? 10 : 5);

    // f.
    printf("x>y?y>x:x>y expect 0,result is %d\n", x > y ? y > x : x > y);

    return 0;
}