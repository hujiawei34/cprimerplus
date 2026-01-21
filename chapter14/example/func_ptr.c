// 使用函数指针
#include "../../my.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 81
char showmenu(void);
void eatline(void);                       // 读取至行尾
void show(void (*fp)(char *), char *str); // 显示字符串
void ToUpper(char *str);                  // 将字符串转换为大写
void ToLower(char *str);                  // 将字符串转换为小写
void Transpose(char *);                   // 大小写转置
void Dummy(char *);                       // 不更改

int main(int argc, char *argv[]) {
  char line[LEN];
  char copy[LEN];
  char choice;
  void (*pfun)(char *);

  puts("Enter a string (empty line to quit):");
  while ((s_gets(line, LEN)) != NULL && line[0] != '\0') {
    while ((choice = showmenu()) != 'n') {
      switch (choice) {
      case 'u':
        pfun = ToUpper;
        break;
      case 'l':
        pfun = ToLower;
        break;
      case 't':
        pfun = Transpose;
        break;
      case 'o':
        pfun = Dummy;
        break;
      }
      strcpy(copy, line);
      show(pfun, copy);
    }
    puts("Enter a string (empty line to quit):");
  }
  puts("Bye!");

  return 0;
}
char showmenu(void) {
  char ans;
  puts("Enter menu choice:");
  puts("u) upper case l) lower case ");
  puts("t) transpose  o) original ");
  puts("n) next string");
  ans = getchar();
  ans = tolower(ans);
  eatline();
  while (strchr("ulton", ans) == NULL) {
    puts("Please enter a u,l,t,o or n:");
    ans = tolower(getchar());
    eatline();
  }
  return ans;
}
void eatline(void) {
  while (getchar() != '\n')
    continue;
}
void ToUpper(char *str) {
  while (*str) {
    *str = toupper(*str);
    str++;
  }
}
void ToLower(char *str) {
  while (*str) {
    *str = tolower(*str);
    str++;
  }
}
void Transpose(char *str) {
  while (*str) {
    if (islower(*str))
      *str = toupper(*str);
    else if (isupper(*str))
      *str = tolower(*str);
    str++;
  }
}
void Dummy(char *str) {
}
void show(void (*fp)(char *), char *str) {
  fp(str);
  puts(str);
}
