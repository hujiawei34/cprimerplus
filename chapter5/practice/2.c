#include <stdio.h>
int main(void)
{
    printf("input a integer:");
    int n;
    scanf("%d",&n);
    int i=0;
    while (i++<10+1){
        printf("%d\n",n);
        n++;
    }
    return 0;
}