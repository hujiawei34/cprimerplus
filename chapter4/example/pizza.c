/* pizza.c -- 在比萨饼程序中使用已定义的常量 */
#include <stdio.h>
#define PI 3.14159
int main(void)
{
    float area, circum, radius;
    printf("Enter the radius of your pizza: ");
    scanf("%f", &radius);
    area = PI * radius * radius;
    circum = 2 * PI * radius;
    printf("Your basic pizza parameters are as follows:\n");
    printf("circumference = %1.2f units\n", circum);
    printf("area = %1.2f square units\n", area);
    return 0;
}