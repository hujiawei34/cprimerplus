#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
void show_array(const double ar[],int n);
double * new_d_array(int n,...);

int main(int argc, char *argv[])
{
    double *p1,*p2;
    p1=new_d_array(5,1.2,2.3,3.4,4.5,5.6);
    p2=new_d_array(4,100.0,20.00,8.08,-1890.0);
    show_array(p1,5);
    show_array(p2,4);

    free(p1);
    free(p2);

    return 0;
}
double * new_d_array(int n,...)
{
    va_list va;
    va_start(va,n);
    double *re=malloc(n*sizeof(double));

    for(int i=0;i<n;i++)
    {
        re[i]=va_arg(va,double);
    }
    va_end(va);
    return re;
}
void show_array(const double ar[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%7g ",ar[i]);
    }
    puts("");

}