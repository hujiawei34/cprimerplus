/* cmpflt.c -- 比较浮点数 */
#include <stdio.h>
#include <math.h>
int main(void)
{
    const double ANSWER=3.1415926;
    double response;
    
    printf("What is the value of pi?\n");
    scanf("%lf", &response);
    while (fabs(response-ANSWER) > 0.00001) {
        printf("Try again:");
        scanf("%lf", &response);
    }
    printf("Close enough.\n");
    return 0;
}