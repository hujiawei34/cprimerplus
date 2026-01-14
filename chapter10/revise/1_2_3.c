#include <stdio.h>
int main(void)
{
    //1.
    int ref[] = {8, 4, 0, 2};
    int *ptr;
    int index;
    for (index = 0, ptr = ref; index < 4; index++, ptr++)
        printf("%d %d\n", ref[index], *ptr);
    //2. ref 有4个元素

    //3.1 ref的地址是数组的首个元素的地址
    printf("ref location %p,ref value is %d\n",&ref,*ref);
    //3.2 ref+1 =ref[1] 第2个元素的地址
    int * p2=ref+1;
    printf("ref+1 location %p,ref+1 value is %d\n",&p2,*p2);

    //3.3 ++ref 不是有效的表达式，因为ref 是常量，不是变量，无法自增
    // printf("++ref locaction %p,++ref value is %d\n",&++ref,*(++ref));


    return 0;
}