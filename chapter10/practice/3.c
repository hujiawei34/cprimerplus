#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print_arr(int[], int n);
int max(int ar[], int n);
int main(void)
{
    int ar[10];
    srandom((unsigned int)time(NULL));

    for (int i = 0; i < 10; i++)
        ar[i] = (int)random() % 1000;
    print_arr(ar, 10);
    printf("max is %d\n",max(ar,10));
    return 0;
}

void print_arr(int ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", ar[i]);
    putchar('\n');
}
/**
 * return max of ar
 */
int max(int ar[], int n)
{
    int max=ar[0];
    for (int i = 0; i < n; i++)
        max = ar[i] > max ? ar[i] : max;
    return max;
}