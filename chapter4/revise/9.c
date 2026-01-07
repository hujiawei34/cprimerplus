#include <stdio.h>
void input_a(void);
void input_b(void);
void input_c(void);
void input_d(void);
void input_e(void);
int main(void)
{
    // a.
    //  input_a();
    // b.
    // input_b();
    // c.
    // input_c();
    // d.
    input_d();
    // e.
    input_e();
    return 0;
}
void input_e(void)
{
    // d.
    printf("current input e\n");
    printf("please enter a string and a integer:\n");
    char str[100];
    int n;
    scanf("%d", &n);
    printf("You entered : %d\n", n);
    printf("==================\n");
}
void input_d(void)
{
    // d.
    printf("current input d\n");
    printf("please enter a string and a integer:\n");
    char str[100];
    int n;
    scanf("%s %d", str, &n);
    printf("You entered: %s and %d\n", str, n);
    printf("==================\n");
}
void input_c(void)
{

    printf("current input c\n");
    printf("Please enter a string:\n");

    char str[100];
    scanf("%s", str);
    printf("You entered: %s\n", str);
    printf("==================\n");
}

void input_b(void)
{
    printf("current input b\n");
    // b.
    printf("Please enter two floating-point numbers:\n");
    float f1, f2;
    scanf("%f %e", &f1, &f2);
    printf("You entered: %g and %g\n", f1, f2);
    printf("==================\n");
}
void input_a(void)
{
    printf("current input a\n");
    // a.
    int input;
    // scanf("%d", &input);
    printf("You entered: %d\n", input);
    printf("==================\n");
}