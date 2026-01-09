#include <stdio.h>
/**
input an upper case char:E
===============
    A    
   ABA   
  ABCBA  
 ABCDCBA 
ABCDEDCBA
 */
int main(void)
{
    char input;
    printf("input an upper case char:");
    scanf("%c", &input);
    printf("===============\n");
    int d = input - 'A'; // diff with a ,d=5
    for (int i = 0; i <= d; i++)
    {
        for (int j = d - i; j > 0; j--)
            printf(" ");
        for (int k = 0; k <= i; k++)
            printf("%c", input - d + k);
        for (int n = i - 1; n >= 0; n--)
            printf("%c", input - d + n);
        printf("\n");
    }
    return 0;
}