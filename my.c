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