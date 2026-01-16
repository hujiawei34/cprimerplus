/* sort_str.c -- 输入字符串，并排序字符串*/
#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 20
#define HALT ""
void stsrt(char *str[], int n);
char *s_gets(char *st, int n);
int main(void) {
  char input[LIM][SIZE];
  char *ptstr[LIM]; // 指针数组
  int ct = 0;
  int k;

  printf("Input up to %d lines, and i will sort them.\n", LIM);
  printf("To stop, press the enter key at the start of a line.\n");
  while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0') {
    ptstr[ct] = input[ct];
    ct++;
  }
  stsrt(ptstr, ct);
  printf("Sorted strings:\n");
  for (k = 0; k < ct; k++)
    puts(ptstr[k]);
  return 0;
}
void stsrt(char *str[], int n) {
  char *temp;
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (strcmp(str[j], str[j + 1]) > 0) {
        temp = str[j];
        str[j] = str[j + 1];
        str[j + 1] = temp;
      }
}
char *s_gets(char *st, int n) {
  char *ret_val;
  ret_val = fgets(st, n, stdin);
  if (ret_val) {
    int i = 0;
    while (st[i] != '\n' && st[i] != '\0')
      i++;
    if (st[i] == '\n')
      st[i] = '\0'; // 替换换行符
    else
      while (getchar() != '\n')
        continue;
  }
  return ret_val;
}