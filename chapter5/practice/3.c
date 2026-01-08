#include <stdio.h>
int main(void)
{
    const int DAYS_PER_WEEK = 7;
    printf("input a integer of day nums:");
    int n;
    scanf("%d",&n);
    while( n>0){
        printf("%d days = %d weeks %d days\n",n,n/DAYS_PER_WEEK,n%DAYS_PER_WEEK);
        printf("input a integer of day nums(<=0 to exit):");
        scanf("%d",&n);
    }
    return 0;
}