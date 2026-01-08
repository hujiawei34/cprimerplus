#include <stdio.h>
void func_a(void);
void func_b(void);
void func_c(void);
int main(void)
{
    // func_a();
    // func_b();
    func_c();
    return 0;
}
void func_c(void){
    printf("===c====\n");
    char ch='s';
    while(ch<'w')
    {
        printf("%c\n",ch);
        ch++;
    }
    printf("%c\n",ch);
    /*
    s
    t
    u
    v
    w
    */
}
void func_a(void){
    printf("===a====\n");
    int x=0;
    
    while(++x<3)
        printf("%4d",x);
    /*   1   2*/

}
void func_b(void){
    printf("===b====\n");
    int x=100;
    
    while(++x<103)
        printf("%4d\n",x);
        printf("%4d\n",x);
    /* 101 102 103*/
}