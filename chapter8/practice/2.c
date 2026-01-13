#include <stdio.h>

int main(void)
{
    int ch;
    int count = 0;  // 计数器，用于每行打印10对值

    printf("请输入字符（Ctrl+D 或 Ctrl+Z 结束）：\n");

    while ((ch = getchar()) != EOF)
    {
        // 处理换行符
        if (ch == '\n')
        {
            printf("\\n %3d\n", ch);
            count = 0;  // 遇到换行符，重置计数器
        }
        // 处理制表符
        else if (ch == '\t')
        {
            printf("\\t %3d  ", ch);
            count++;
            if (count % 10 == 0)
                printf("\n");
        }
        // 处理其他控制字符（ASCII 0-31）
        else if (ch >= 0 && ch < 32)
        {
            printf("^%c %3d  ", ch + 64, ch);
            count++;
            if (count % 10 == 0)
                printf("\n");
        }
        // 处理 DEL 字符（ASCII 127）
        else if (ch == 127)
        {
            printf("^? %3d  ", ch);
            count++;
            if (count % 10 == 0)
                printf("\n");
        }
        // 处理普通可打印字符
        else
        {
            printf("%c %3d  ", ch, ch);
            count++;
            if (count % 10 == 0)
                printf("\n");
        }
    }

    // 如果最后一行没有满10个，补充换行
    if (count % 10 != 0)
        printf("\n");

    return 0;
}
