#include <stdio.h>
int main(void)
{
    float cups_per_pint = 2;
    float ans_per_cup = 8;
    float spoons_per_ans = 2;
    float tee_spoons_per_spoon = 3;
    float cups_input;
    printf("Enter the number of cups:");
    scanf("%f", &cups_input);
    printf("%.2f cups is %.2f teaspoons.\n", cups_input, cups_input * cups_per_pint * ans_per_cup * spoons_per_ans * tee_spoons_per_spoon);
    printf("%.2f cups is %.2f tablespoons.\n", cups_input, cups_input * cups_per_pint * ans_per_cup * spoons_per_ans);
    printf("%.2f cups is %.2f fluid ounces.\n", cups_input, cups_input * cups_per_pint * ans_per_cup);
    printf("%.2f cups is %.2f pints.\n", cups_input, cups_input * cups_per_pint);

    return 0;
}