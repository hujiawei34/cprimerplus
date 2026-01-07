#include <stdio.h>
int main(void)
{
    printf("Please enter your height in centimeters: ");
    float height;
    scanf("%f", &height);
    printf("now enter you name: ");
    char name[30];
    scanf("%s", name);
    printf("%s, you are %.1f inches tall\n", name, height / 2.54);
    return 0;
}