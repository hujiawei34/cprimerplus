#include <stdio.h>
int main(void)
{
    printf("====a====\n");
    float input_a;
    printf("Please enter a floating point number: ");
    scanf("%f", &input_a);
    printf("输入%g 或 %.1e\n", input_a, input_a);

    printf("====b====\n");
    float input_b;
    printf("Please enter a floating point number: ");
    scanf("%f", &input_b);
    printf("输入%+8.3f 或 %8.3E\n", input_b, input_b);
    return 0;
}
