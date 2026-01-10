#include <stdio.h>
long calc(int lower, int upper)
{
    long result = 0;
    for (int i = lower; i <= upper; i++)
    {
        result += i * i;
    }
    return result;
}
int main(void)
{
    printf("Enter lower and upper integer limits: ");
    int upper, lower;
    int status;
    scanf("%d %d", &lower, &upper);
    while (upper > lower)
    {
        printf("The sums of the squares from %d to %d is %ld\n", lower, upper, calc(lower, upper));
        printf("Enter next set of limits:");
        scanf("%d %d", &lower, &upper);
    }

    return 0;
}