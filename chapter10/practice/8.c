#include <stdio.h>
void copy_arr(int *tar,int *sar,int n)
{
    for(int i=0;i<n;i++)
        *tar++=*sar++;
}
void print_arr(int ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", ar[i]);
    putchar('\n');
}
int main(void)
{
    int s[7]={1,2,3,4,5,6,7};
    int t[3];
    copy_arr(t,&s[2],3);
    print_arr(t,3);
    
    return 0;
}