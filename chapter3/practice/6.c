#include <stdio.h>
int main(void)
{
    double g_per_water = 3.0e-23;
    double g_per_quato = 950;
    double input;
    printf("Enter the number of quatos:");
    scanf("%lf", &input);
    printf("The number of grams in %.2f quatos of water is %.3e grams.\n", input, g_per_quato * input * g_per_water);
    return 0;
}