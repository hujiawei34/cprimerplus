#include <stdio.h>
int main(void)
{
    int quack=2;
    quack +=5;//7
    quack *=10;//70
    quack -=6;//64
    quack /=8;//8
    quack %=3;//2
    printf("quack=%d\n",quack);
    return 0;
}