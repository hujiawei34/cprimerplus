#include <stdio.h>
long func_12(void);
long func_13(int n);
void func_14(void)
{
    int k;
    for (k = 1, printf("%d:Hi!\n", k); printf("k=%d\n", k), k * k < 26; k += 2, printf("Now k is %d\n", k))
        printf("k is %d in the loop\n", k);
    /**
     * 1:Hi
     * k=1
     * k is 1 in the loop
     * Now k is 3
     * k=3
     * k is 3 in the loop
     * Now k is 5
     * k=5
     * k is 5 in the loop
     * Now k is 7
     * k=7
     */
}
int main(void)
{
    func_12();
    func_13(11);
    func_14();

    return 0;
}
long func_12(void)
{
    long l = 12L;
    printf("func 11 return long \n");
    return l;
}
long func_13(int n)
{
    long npow = n * n;
    printf("func 13 return %d * %d= %ld\n", n,n, npow);
    return npow;
}