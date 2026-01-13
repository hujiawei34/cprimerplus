#include <stdio.h>
#include <math.h>
void print_choice()
{
    printf("Enter the operation of your choice:\n");
    printf("a. add\t");
    printf("s. subtract\t\n");
    printf("m. multiply\t");
    printf("d. divide\t\n");
    printf("q. quit\t\n");
}
double get_float(char choice)
{
    double a;
    int status = scanf("%lf", &a);
    while (status != 1 || (choice == 'd' && fabs(a) == 0))
    {
        if (status == 1)
        {
            printf("when divide,the second number can not be zero,enter another one:");
        }
        else
        {
            char input[40];
            scanf("%s", input);
            printf("%s is not an number.\n", input);
            printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
        }
        while (getchar() != '\n')
            ;
        status = scanf("%lf", &a);
    }
    while (getchar() != '\n')
        ;
    return a;
}
char get_choice()
{
    char ch = getchar();
    while (getchar() != '\n')
        ;
    while (!(ch == 'a' || ch == 's' || ch == 'm' || ch == 'd' || ch == 'q'))
    {
        printf("invalid input,input a,s,m,d,q:");
        ch = getchar();
        while (getchar() != '\n')
            ;
    }
    return ch;
}
int main(void)
{
    print_choice();
    char ch = get_choice();
    while (ch != 'q')
    {
        printf("Enter first number: ");
        double a = get_float(ch);
        printf("Enter second number: ");
        double b = get_float(ch);
        switch (ch)
        {
        case 'a':
            printf("%g + %g = %g", a, b, a + b);
            break;
        case 's':
            printf("%g - %g = %g", a, b, a - b);
            break;

        case 'm':
            printf("%g * %g = %g", a, b, a * b);
            break;

        case 'd':
            printf("%g / %g = %g", a, b, a / b);
            break;

        default:
            break;
        }
        printf("\n");
        print_choice();
        ch = get_choice();
    }
    printf("Bye.");

    return 0;
}