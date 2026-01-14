#include <stdio.h>
void func_a(void)
{
    
    int (*ptr)[2];//指向int[2]的指针，步长2 int;
    int torf[2][2]={12,14,16};//{{12,14},{16,0}}
    ptr=torf;//->12 lenth=2 * int
    //** **ptr=12 **(ptr+1) =*torf[1]=torf[1][0]=16 */
    printf("**ptr=%d,**(ptr+1)=%d\n",**ptr,**(ptr+1));
}
void func_b(void)
{
    int (*ptr)[2];
    int fort[2][2]={{12},{12,16}};
    ptr=fort;
    //同上，torf[1][0]=12
    printf("**ptr=%d,**(ptr+1)=%d\n",**ptr,**(ptr+1));
}
int main(void)
{
    func_a();
    func_b();
    return 0;
}