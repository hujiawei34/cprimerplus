#include <stdio.h>
int main(void)
{
    float cm_per_inch = 2.54;
    float cm_input;
    printf("Enter your height in cm: ");
    scanf("%f", &cm_input);
    printf("Your height in inches is %.2f inches.\n", cm_input / cm_per_inch);
    return 0;
}