#include <stdio.h>
void alter(int *x, int *y)
{
    int sum, diff;
    sum = *x + *y;
    diff = *x - *y;
    *x=sum;
    *y=diff;

}
int main(void)
{
    int x,y;
    while((scanf("%d %d",&x,&y)==2))
    {
        printf("x=%d,y=%d\n",x,y);
        alter(&x,&y);
        printf("x=%d,y=%d\n",x,y);
    }
    return 0;
}