#include <stdio.h>
int str_sch(char *str, char ch) {
  int i = 0;
  while (str[i]) {
    if (str[i] == ch) {
      return i;
    }
    i++;
  }
  return 0;
}
int main(void) {
  while (1) {
    char str[100];
    char ch;
    printf("请输入一个字符串:");
    fgets(str, 100, stdin);
    printf("请输入一个字符:");
    ch = getchar();
    while (getchar() != '\n') {
      continue;
    }
    int pos = str_sch(str, ch);
    if (pos) {
        printf("字符%c在字符串%s中的位置是%d\n", ch, str, pos + 1);
    } else {
        printf("字符%c不在字符串%s中\n", ch, str);
    }
  }
  return 0;
}