#include <stdio.h>
int main(void)
{
    printf("input an integer of table line limits:");
    int limit;
    scanf("%d", &limit);
    printf("-----------------------------\n");
    printf("|\tn|\tn^2|\tn^3|\n");
    for (int i = 1; i < limit; i++)
    {
        printf("|\t%4d", i);
        printf("|\t%4d", i * i);
        printf("|\t%4d|\n", i * i * i);
    }
    printf("-----------------------------\n");
    return 0;
}