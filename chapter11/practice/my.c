#include "my.h"
#include <stdio.h>
#include <string.h>
/**
 * @brief 从标准输入读取字符串
 * 
 * 从标准输入读取最多n-1个字符到字符串s中，以换行符结束。
 * 如果输入的字符数超过n-1个，超过的字符将被丢弃。
 * 
 * @param s 用于存储读取字符串的字符数组
 * @param n 数组s的大小，必须大于等于2
 * @return char* 指向读取到的字符串的指针，如果读取失败返回NULL
 */
char *s_gets(char *s, int n) {
  char *ret_val;
  int i = 0;
  ret_val = fgets(s, n, stdin);
  if (ret_val) {
    char *find = strchr(s, '\n');
    if (find)
      *find = '\0';
    else
      while (getchar() != '\n')
        continue;
  }
  return ret_val;
}
/**
 * @brief 从文件读取多行字符串
 * 
 * 从指定的文件读取最多LINES行字符串，每行最多LENGTH_LIMIT-1个字符。
 * 读取的字符串将存储在二维字符数组str中，每个字符串以null字符结尾。
 * 
 * @param str 二维字符数组，用于存储读取的字符串
 * @return int 成功读取的行数，如果读取失败返回-1
 */
int read_file_lines(char str[LINES][LENGTH_LIMIT]) {
  FILE *fp;
  char *filename = "11_input.txt";
  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", filename);
    return -1;
  }
  int i = 0;
  while (fgets(str[i], LENGTH_LIMIT, fp) != NULL && i < LINES) {
    i++;
  }
  str[i][0]='\0';
  fclose(fp);
  return i;
}