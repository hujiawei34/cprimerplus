#include <stdio.h>
int main(void)
{
    //a.
    int x = 6;
    if (x > 5)
    {
        printf("x>6\n");
    }
    //b.
    printf("-====start read a double ====\n");
    double x2;
    if (scanf("%lf", &x2) != 1)
    {
        printf("failed to read double\n");
    }

    //c.
    x=5;
    if(x==5){
        printf("x=5 is true\n");
    }
    return 0;
}