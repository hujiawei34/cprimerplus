#define MIN_PER_HOUR 60
#include <stdio.h>
int main(void)
{
    int min;
    printf("请输入分钟数：");
    scanf("%d",&min);
    while(min>0){
        printf("%d分钟 = %d小时 %d分钟\n",min,min/MIN_PER_HOUR,min%MIN_PER_HOUR);
        printf("请输入分钟数：");
        scanf("%d",&min);
    }
    return 0;
}