#include <stdio.h>
#define BASE_SINGLE 17850
#define BASE_OWNER 23900
#define MARIED_SHARE 29750
#define MARIED_ALONE 14875
#define RATE1 0.15
#define RATE2 0.28
void print_choice(void)
{
    const int n = 30;
    for (int i = 0; i < n; i++)
        putchar('=');
    putchar('\n');

    printf("1) single\t\t2) house owner\n3) married and share\t\t 4) married but alone\n5) quit\n");
    for (int i = 0; i < n; i++)
        putchar('=');
    putchar('\n');
    printf("input your choice:");
}
double get_salary(void)
{
    printf("input your salary:");
    double salary;
    int status = scanf("%lf", &salary);
    while (status != 1 || salary < 0)
    {
        while (getchar() != '\n')
            ;

        printf("invalid input,input a number of salary:");
        status = scanf("%lf", &salary);
    }
    return salary;
}
int get_choice(void)
{
    int choice;
    int status = scanf("%d", &choice);
    while (status != 1 || choice > 5 || choice < 1)
    {
        while (getchar() != '\n')
            ;
        printf("invalid input,select 1~5 as above.\n");
        status = scanf("%d", &choice);
    }
    return choice;
}
double calc_tax(double base, double salary)
{
    double tax;
    if (salary < base)
        tax = salary * RATE1;
    else
        tax = base * RATE1 + (salary - base) * RATE2;
    return tax;
}
int main(void)
{
    double base, salary, tax;
    print_choice();
    int choice = get_choice();
    while (choice != 5)
    {
        switch (choice)
        {
        case 1:
            base = BASE_SINGLE;
            break;
        case 2:
            base = BASE_OWNER;
            break;
        case 3:
            base = MARIED_SHARE;
            break;
        case 4:
            base = MARIED_ALONE;
            break;
        }
        salary = get_salary();
        tax = calc_tax(base, salary);
        printf("Your tax for salary %.2f is %.2f\n", salary, tax);
        print_choice();
        choice=get_choice();
    }
    return 0;
}