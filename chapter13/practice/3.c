#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main(void)
{
    printf("Enter a filenmae:");
    char filename[41];
    scanf("%40s", filename);
    FILE *fp;
    if ((fp = fopen(filename, "r+")) == NULL)
    {
        fprintf(stderr, "can not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    char ch;
    while ((ch = getc(fp)) != EOF)
    {
        fseek(fp, -1, SEEK_CUR);
        putc(toupper(ch), fp);
        /**
         *   1. C标准库的读写切换规则：
    - 当你用 "r+" 模式打开文件时，可以同时读写
    - 但是在读操作和写操作之间切换时，C标准要求必须调用一个文件定位函数（fseek, fsetpos, rewind）或遇到 EOF
    - 同样，从写操作切换到读操作时也需要这样做
  2. 你的代码流程：
  ch = getc(fp);           // 读操作
  fseek(fp, -1, SEEK_CUR); // 定位函数（读→写切换）
  putc(toupper(ch), fp);   // 写操作
  fseek(fp, 0, SEEK_CUR);  // 定位函数（写→读切换）← 为下一次循环的getc()做准备
  3. 如果没有第二个 fseek：
    - 某些系统上可能工作正常（因为实现细节）
    - 但在严格遵循C标准的系统上可能导致未定义行为
    - 可能出现缓冲区不同步，读取到错误的数据
         */
        fseek(fp, 0, SEEK_CUR);
    }

    // fgets()
    fclose(fp);

    return 0;
}