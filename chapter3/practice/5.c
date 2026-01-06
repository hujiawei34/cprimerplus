#include <stdio.h>
int main(void)
{
    double seconds_per_year = 3.156e7;
    int age;
    printf("Enter your age in years: ");
    scanf("%d", &age);
    printf("You have lived for %.4f seconds.\n", age * seconds_per_year);
    return 0;
}