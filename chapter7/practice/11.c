#include <stdio.h>
#define PRICE_A 2.05 // 洋蓟
#define PRICE_B 1.15 // 甜菜
#define PRICE_C 1.09 // 胡萝卜
#define RATE 0.05    // 优惠每100美元
#define FREIGHT1 6.5 //<5磅运费
#define POUND_GAP1 5 // 5 磅
#define FREIGHT2 14  // 5~20 磅运费
#define POUND_GAP2 20
#define FREIGHT_RATE 0.5 // 超过20磅每续重1磅增加0.5美元
double calc_freight(double w)
{
    double result;
    if (w <= POUND_GAP1)
        result = FREIGHT1;
    else if (w <= POUND_GAP2)
        result = FREIGHT2;
    else
    {
        int left_w = (int)w - POUND_GAP2;
        result = FREIGHT2 + left_w * FREIGHT_RATE;
    }
    return result;
}
void show_hello(void)
{
    int n = 30;
    for (int i = 0; i < n; i++)
        putchar('=');
    putchar('\n');
    printf("欢迎光临ABC杂货铺！\n");
    for (int i = 0; i < n; i++)
        putchar('=');
    putchar('\n');
}
void show_goods(void)
{
    // 商品展示，可以先选择商品，
    int n = 30;
    for (int i = 0; i < n; i++)
        putchar('=');
    putchar('\n');
    printf("a) 洋蓟 %.2f 美元/磅\nb) 甜菜 %.2f 美元/磅\nc) 胡萝卜 %.2f 美元/磅\nq) 退出\n", PRICE_A, PRICE_B, PRICE_C);
    for (int i = 0; i < n; i++)
        putchar('=');
    putchar('\n');
}
char get_choice()
{
    printf("输入对应字母，选择商品：");
    char ch;
    ch = getchar();
    while (getchar() != '\n')
        ;
    while (ch != 'a' && ch != 'b' && ch != 'c' && ch != 'q')
    {
        printf("输入不合法！\n");
        show_goods();
        printf("输入对应字母，选择商品：");
        ch = getchar();
        while (getchar() != '\n')
            ;
    }
    return ch;
}
double get_weight()
{
    printf("输入购买重量（单位磅):");
    double w; // weight
    int status = scanf("%lf", &w);
    while (getchar() != '\n');
    while (status != 1 ||  w < 0)
    {
        while (getchar() != '\n')
            ;
        printf("输入不合法！\n");
        printf("输入购买重量（单位磅):");
        status = scanf("%lf", &w);
        while (getchar() != '\n');
    }
    return w;
}

int main(void)
{
    char choice;
    double w_list[3];
    double money_of_goods[3];
    double w_sum = 0;
    double order_money_sum = 0;
    double discount = 0;
    double freight = 0;
    double money_after_discount = 0;
    for (int i = 0; i < 3; i++)
    {
        w_list[i] = 0;
        money_of_goods[i] = 0;
    }

    double price_list[3];
    price_list[0] = PRICE_A;
    price_list[1] = PRICE_B;
    price_list[2] = PRICE_C;

    show_hello();
    show_goods();
    choice = get_choice();
    while (choice != 'q')
    {
        double w = get_weight();
        int index;
        switch (choice)
        {
        case 'a':
            index = 0;
            break;
        case 'b':
            index = 1;
            break;
        case 'c':
            index = 2;
            break;
        }
        w_list[index] += w;
        money_of_goods[index] = price_list[index] * w_list[index];
        // 订单总重和总价
        for (int i = 0; i < 3; i++)
        {
            w_sum += w_list[i];
            order_money_sum += money_of_goods[i];
        }
        // 订单优惠
        if (order_money_sum > 100)
            discount = order_money_sum * RATE;
        // 运费
        freight = calc_freight(w_sum);
        // 优惠后总价
        money_after_discount = order_money_sum - discount + freight;
        for (int i = 0; i < 60; i++)
            putchar('-');
        putchar('\n');
        printf("| %-44s |\n", "当前订单：");
        for (int i = 0; i < 60; i++)
            putchar('-');
        putchar('\n');
        printf("| %-14s | %-10s | %-10s | %-10s |\n", "品名", "洋蓟", "甜菜", "胡萝卜");
        for (int i = 0; i < 60; i++)
            putchar('-');
        putchar('\n');
        printf("| %-14s | %10.2f | %10.2f | %10.2f |\n", "单价", PRICE_A, PRICE_B, PRICE_C);
        for (int i = 0; i < 60; i++)
            putchar('-');
        putchar('\n');
        printf("| %-14s | %10.2f | %10.2f | %10.2f |\n", "计重", w_list[0], w_list[1], w_list[2]);
        for (int i = 0; i < 60; i++)
            putchar('-');
        putchar('\n');
        printf("| %-14s | %10.2f | %10.2f | %10.2f |\n", "费用", money_of_goods[0], money_of_goods[1], money_of_goods[2]);
        for (int i = 0; i < 60; i++)
            putchar('-');
        putchar('\n');
        printf("| %-14s | %30.2f |\n", "订单总费用：", order_money_sum);
        for (int i = 0; i < 60; i++)
            putchar('-');
        putchar('\n');
        printf("| %-14s | %30.2f |\n", "折扣：", discount);
        for (int i = 0; i < 60; i++)
            putchar('-');
        putchar('\n');
        printf("| %-14s | %30.2f |\n", "运费：", freight);
        for (int i = 0; i < 60; i++)
            putchar('-');
        putchar('\n');
        printf("| %-14s | %30.2f |\n", "总计：", money_after_discount);
        for (int i = 0; i < 60; i++)
            putchar('-');
        putchar('\n');
        putchar('\n');
        putchar('\n');
        show_goods();
        choice = get_choice();
    }
    return 0;
}