#include <stdio.h>
int main(void)
{
    int input_acsii_number;
    printf("Please enter an ASCII number:");
    scanf("%d", &input_acsii_number);
    printf("The character for ASCII number %d is '%c'\n", input_acsii_number, input_acsii_number);
    return 0;
}