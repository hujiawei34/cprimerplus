#include <stdio.h>
int main(void)
{
    int weight, height; /* weight 以磅为单位, height 以英寸为单位 */

    printf("请输入体重(磅)和身高(英寸): ");
    scanf("%d %d", &weight, &height);

    if (height >= 72) {
        printf("You are very tall for your weight.\n");
    } else if (height >= 64) {
        if (weight >= 100) {
            printf("You are tall for your weight.\n");
        } else {
            printf("Your weight is ideal.\n");
        }
    } else if (height >= 48) {
        if (weight > 300) {
            printf("You are quite short for your weight.\n");
        } else {
            printf("Your weight is ideal.\n");
        }
    } else {
        printf("You are quite short for your weight.\n");
    }

    return 0;
}
