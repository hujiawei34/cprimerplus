#include <stdio.h>

/**
 * 程序功能：打印字母金字塔
 * 输入一个大写字母，打印从 A 开始到该字母的金字塔图案
 *
 * 示例：输入 E
 * ===============
 *     A
 *    ABA
 *   ABCBA
 *  ABCDCBA
 * ABCDEDCBA
 */
int main(void)
{
    char input;
    printf("input an upper case char:");
    scanf("%c", &input);
    printf("===============\n");

    // 计算金字塔的行数（例如：输入 E，则 rows = 4，共 5 行：0-4）
    int rows = input - 'A';

    // 遍历每一行
    for (int row = 0; row <= rows; row++)
    {
        // 打印左侧空格（每行空格数 = 总行数 - 当前行数）
        for (int space = rows - row; space > 0; space--)
            printf(" ");

        // 打印左半部分字符（从 A 递增到当前行对应的字母）
        for (int left_char = 0; left_char <= row; left_char++)
            printf("%c", 'A' + left_char);

        // 打印右半部分字符（从当前行前一个字母递减到 A）
        for (int right_char = row - 1; right_char >= 0; right_char--)
            printf("%c", 'A' + right_char);

        printf("\n");
    }

    return 0;
}