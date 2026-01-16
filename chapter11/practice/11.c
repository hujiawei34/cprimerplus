#include <stdio.h>
#include <string.h>
#include "my.h"
void show_menu(void) {
  printf("请选择要执行的操作：\n");
  printf("1. 打印源字符串列表\n");
  printf("2. 以ACSII中的顺序打印字符串\n");
  printf("3. 按长度递增顺序打印字符串\n");
  printf("4. 按字符串中第1个单词的长度打印字符串\n");
  printf("5. 退出程序\n");
}
// 辅助函数：计算第一个单词的长度
int get_first_word_len(const char *str) {
  int len = 0;
  // 跳过开头的空白符（如果需要）
  while (*str == ' ' || *str == '\t')
    str++;

  // 计算单词长度直到遇到空格或结束符
  while (*str != '\0' && *str != ' ' && *str != '\n') {
    len++;
    str++;
  }
  return len;
}
void print_str_sort_firstwordlen(char str[LINES][LENGTH_LIMIT]) {

  char new_str[LINES][LENGTH_LIMIT];
  for (int i = 0; i < LINES; i++) {
    strcpy(new_str[i], str[i]);
  }
  // 修改后的循环部分
  for (int i = 0; i < LINES; i++) {
    for (int j = i + 1; j < LINES; j++) {
      // 使用辅助函数，不破坏原字符串
      int len_i = get_first_word_len(new_str[i]);
      int len_j = get_first_word_len(new_str[j]);

      if (len_i > len_j) {
        char tmp[LENGTH_LIMIT];
        strcpy(tmp, new_str[i]);
        strcpy(new_str[i], new_str[j]);
        strcpy(new_str[j], tmp);
      }
    }
  }
  for (int i = 0; i < LINES; i++) {
    printf("%s", new_str[i]);
  }
}
void print_str_sorted_ascii(char str[LINES][LENGTH_LIMIT]) {
  char new_str[LINES][LENGTH_LIMIT];
  for (int i = 0; i < LINES; i++) {
    strcpy(new_str[i], str[i]);
  }
  for (int i = 0; i < LINES; i++) {
    for (int j = i + 1; j < LINES; j++) {
      if (strcmp(new_str[i], new_str[j]) > 0) {
        char tmp[LENGTH_LIMIT];
        strcpy(tmp, new_str[i]);
        strcpy(new_str[i], new_str[j]);
        strcpy(new_str[j], tmp);
      }
    }
  }
  for (int i = 0; i < LINES; i++) {
    printf("%s", new_str[i]);
  }
}
void print_str_sort_length(char str[LINES][LENGTH_LIMIT]) {
  char new_str[LINES][LENGTH_LIMIT];
  for (int i = 0; i < LINES; i++) {
    strcpy(new_str[i], str[i]);
  }
  for (int i = 0; i < LINES; i++) {
    for (int j = i + 1; j < LINES; j++) {
      if (strlen(new_str[i]) > strlen(new_str[j])) {
        char tmp[LENGTH_LIMIT];
        strcpy(tmp, new_str[i]);
        strcpy(new_str[i], new_str[j]);
        strcpy(new_str[j], tmp);
      }
    }
  }
  for (int i = 0; i < LINES; i++) {
    printf("%s", new_str[i]);
  }
}
int get_menu_choice(void) {
  int choice;
  printf("请输入您的选择：");
  int status = scanf("%d", &choice);
  while (status != 1 && (choice < 1 || choice > 5)) {
    printf("输入错误，请输入1~5整数\n");
    while (getchar() != '\n')
      ;
    status = scanf("%d", &choice);
  }
  return choice;
}
void print_str_list(char str[LINES][LENGTH_LIMIT], int lines) {
  for (int i = 0; i < lines; i++) {
    printf("%s", str[i]);
  }
}
int main(void) {
  char str[LINES][LENGTH_LIMIT];
  int lines = read_file_lines(str);
  int choice;
  show_menu();
  choice = get_menu_choice();
  while (choice != 5) {
    switch (choice) {
    case 1:
      print_str_list(str, lines);
      break;
    case 2:
      print_str_sorted_ascii(str);
      break;
    case 3:
      print_str_sort_length(str);
      break;
    case 4:
      print_str_sort_firstwordlen(str);
      break;
    }
    show_menu();
    choice = get_menu_choice();
  }

  return 0;
}