#include <stdio.h>
#define ROWS 3
#define COLS 5
void get_input(double ar[ROWS][COLS])
{
    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLS; j++)
        {
            int s = scanf("%lf", &ar[i][j]);
            getchar();
        }
    }
}
double avg(double ar[COLS])
{
    double sum = 0;
    for (size_t i = 0; i < COLS; i++)
        sum += ar[i];
    return sum / COLS;
}
double all_avg(double ar[ROWS][COLS])
{
    double total = 0;
    for (size_t i = 0; i < ROWS; i++)
        total += avg(ar[i]);
    return total / ROWS;
}
double get_max(double ar[ROWS][COLS])
{
    double max = ar[0][0];
    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLS; j++)
        {
            max = ar[i][j] > max ? ar[i][j] : max;
        }
    }
    return max;
}
void print(double ar[ROWS][COLS], double avg, double max)
{
    printf("================\n");
    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLS; j++)
        {
            printf("%g ", ar[i][j]);
        }
        putchar('\n');
    }
    printf("================\n");
    printf("avg:%g\n", avg);
    printf("max:%g\n", max);
}
int main(void)
{
    double d[ROWS][COLS];
    get_input(d);
    double a = all_avg(d);
    double m = get_max(d);
    print(d, a, m);

    return 0;
}