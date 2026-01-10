#include <stdio.h>
int main(void)
{
    double daphne_origin, deirdre_origin, daphne_sum, deirdre_sum;
    daphne_sum = deirdre_sum = daphne_origin = deirdre_origin = 100;
    int year;
    const double daphne_rate = 0.1;
    const double deirdre_rate = 0.05;
    printf("year daphne deirdre\n");
    printf("%4d %6.2f %7.2f\n", year, daphne_sum, deirdre_sum);
    for (year = 1; deirdre_sum <= daphne_sum; year++)
    {
        double daphne_rest = daphne_origin * daphne_rate;
        daphne_sum += daphne_rest;
        double deirdre_rest = deirdre_sum * deirdre_rate;
        deirdre_sum += deirdre_rest;
        printf("%4d %6.2f %7.2f\n", year, daphne_sum, deirdre_sum);
    }
    printf("\n");

    return 0;
}