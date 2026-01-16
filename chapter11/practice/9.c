#include "my.h"
#include <stdio.h>
#include <string.h>
void revert(char str[]) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }
}
int main(void) {
  char str[100];
  printf("请输入一个字符串:");
  s_gets(str, 100);
  revert(str);
  printf("反转后的字符串:%s\n", str);
  return 0;
}