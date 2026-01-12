#include <stdio.h>
#include <stdbool.h>
#define TIME_RATE 1.5
#define WORKTIME_H_A_WEEK 40 // 每周40小时
#define SALARY_GAP1 300
#define RATE1 0.15
#define SALARY_GAP2 150
#define RATE2 0.2
#define RATE3 0.25
void calc(double hours, double base)
{

    double salary;
    if (hours <= WORKTIME_H_A_WEEK)
        salary = base * hours;
    else
        salary = WORKTIME_H_A_WEEK * base + (hours - WORKTIME_H_A_WEEK) * TIME_RATE * base;

    printf("Your salary total is:%.2f\n", salary);
    double tax;
    if (salary < SALARY_GAP1)
        tax = salary * RATE1;
    else if (salary - SALARY_GAP1 <= SALARY_GAP2)
        tax = SALARY_GAP1 * RATE1 + (salary - SALARY_GAP1) * RATE2;
    else
        tax = SALARY_GAP1 * RATE1 + SALARY_GAP2 * RATE2 + (salary - SALARY_GAP1 - SALARY_GAP2) * RATE3;
    printf("tax is %.2f\n", tax);
    printf("净收入=%.2f\n", salary - tax);
}
void print_choice(void)
{
    const int n = 20;
    for (int i = 0; i < n; i++)
        printf("*");
    putchar('\n');
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr\t2) $9.33/hr\n3) $10.0/hr\t4) $11.20/hr\n5) quit\n");
    for (int i = 0; i < n; i++)
        printf("*");
    putchar('\n');
}
int get_choice(void)
{
    int choice;
    int status = scanf("%d", &choice);
    while (status != 1)
    {
        while (getchar() != '\n')
            ;
        printf("invalid input,choose 1~5\n");
        print_choice();
        status = scanf("%d", &choice);
    }
    return choice;
}
void func_8(void)
{
    print_choice();
    double base;
    int choice = get_choice();
    while (choice != 5)
    {
        switch (choice)
        {
        case 1:
            base = 8.75;
            break;
        case 2:
            base = 9.33;
            break;
        case 3:
            base = 10.00;
            break;
        case 4:
            base = 11.20;
            break;
        default:
            printf("invalid input,choose 1~5");
            print_choice();
            choice = get_choice();
            continue;
        }
        printf("Enter work time (hours) per week:");
        double hours;
        int status = scanf("%lf", &hours);
        while (status != 1)
        {
            while(getchar() != '\n');
            printf("invalid number,input an number:");
            status = scanf("%lf", &hours);
        }
        calc(hours, base);
        print_choice();
        choice = get_choice();
    }
}

int main(void)
{
    func_8();
    return 0;
}