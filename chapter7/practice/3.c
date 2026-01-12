#include <stdio.h>
int main(void)
{
    int o_ct; // 偶数count,不含0
    int j_ct; // 奇数count
    int o_sum;
    int j_sum;
    o_sum = j_sum = 0;
    int i;
    int status = scanf("%d", &i);
    while (1)
    {
        if (status != 1)
        {
            getchar();
            status = scanf("%d", &i);
            continue;
        }
        if (i != 0)
        {
            if (i % 2 == 0)
            {
                o_ct++;
                o_sum += i;
            }
            else
            {
                j_ct++;
                j_sum += i;
            }
        }
        else
            break;
        status = scanf("%d", &i);
    }
    printf("偶数个数:%d,偶数平均值:%.1f\n奇数个数:%d,奇数平均值:%.1f\n", o_ct, (float)o_sum / o_ct, j_ct, (float)j_sum / j_ct);

    return 0;
}