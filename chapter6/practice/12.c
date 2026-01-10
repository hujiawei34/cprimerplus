#include <stdio.h>
void seq_a(int limit)
{
    double result = 1;
    printf("%.1f", 1.0);
    _Bool added = 0;
    for (int i = 2; i <= limit; i++)
    {
        result += 1.0 / i;
        if (i > 5)
        {
            if (!added)
            {
                printf("+...");
                added = 1;
            }
            continue;
        }
        printf(" + ");
        printf("%.1f/%.1f", 1.0, (double)i);
    }
    printf("=%.1f\n", result);
}
void seq_b(int limit)
{
    double result = 1;
    printf("%.1f", 1.0);
    _Bool added = 0;
    for (int i = 2; i <= limit; i++)
    {
        if (i % 2)
        {
            result += 1.0 / i;
        }
        else
        {
            result -= 1.0 / i;
        }
        if (i > 5)
        {
            if (!added)
            {
                printf("+...");
                added = 1;
            }
            continue;
        }
        if (i % 2)
        {
            printf(" + ");
        }
        else
        {
            printf(" - ");
        }
        printf("%.1f/%.1f", 1.0, (double)i);
    }
    printf("=%.1f\n", result);
}
int main(void)
{
    printf("input an integer of sequece limits:");
    int limit;
    int status = scanf("%d", &limit);
    while (limit > 0)
    {
        seq_a(limit);
        seq_b(limit);
        printf("Next input an integer of sequece limits:");
        int status = scanf("%d", &limit);
        if (status != 1)
        {
            while (getchar() != '\n')
                ; // 清空缓冲区
            break;
        }
    }
    printf("\n");
    return 0;
}