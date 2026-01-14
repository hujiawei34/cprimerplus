#include <stdio.h>
void sort(double *a, double *b, double *c)
{
    double list[3];
    list[0] = *a;
    list[1] = *b;
    list[2] = *c;
    // double sort_list[3];

    for (int i = 0; i < 3; i++)
    {
        // sort_list[i]=list[i];
        for (int j = i + 1; j < 3; j++)
        {
            if (list[i] > list[j])
            {
                double tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }
    *a = list[0];
    *b = list[1];
    *c = list[2];
}
int main(void)
{
    double d1 = 1.1, d2 = -3.1, d3 = 1.3;
    printf("original d1=%g,d2=%g,d3=%g\n", d1, d2, d3);
    sort(&d1, &d2, &d3);
    printf("original d1=%g,d2=%g,d3=%g\n", d1, d2, d3);
    return 0;
}