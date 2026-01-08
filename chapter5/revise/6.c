#include <stdio.h>
#define FORMAT "%s! C is cool!\n"
int main(void)
{
    int num=10;

    printf("%d\n",1);
    printf(FORMAT,FORMAT);
    printf("%d\n",++num);/*print 11 and num=11*/
    printf("%d\n",num++);/*print 11 and num=12*/
    printf("%d\n",num--);/*print 12 and num=11*/
    printf("%d\n",num);//print 11
    
    return 0;
}