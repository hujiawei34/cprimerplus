/* copy1.c --演示strcpy()函数 */
#include <stdio.h>
#include <string.h>
#define SIZE 40
#define LIM 5
char *s_gets(char *st, int n);
int main(void) {
  char qwords[LIM][SIZE];
  char temp[SIZE];
  int i = 0;

  printf("Enter %d words beginning with q:\n", LIM);
  while (i < LIM && s_gets(temp, SIZE) != NULL) {
    if (temp[0] != 'q')
      printf("%s doesn't begin with q!\n", temp);
    else {
      strcpy(qwords[i], temp);
      i++;
    }
  }
  printf("Here are the words:\n");
  for (i = 0; i < LIM; i++)
    printf("%s\n", qwords[i]);
  return 0;
}

char *s_gets(char *st, int n) {
  char *ret_val;
  ret_val = fgets(st, n, stdin);
  if (ret_val) {
    char *newline = strchr(st, '\n'); // 查找换行符
    if (newline)
      *newline = '\0'; // 将换行符替换为字符串结束符
    else
      while (getchar() != '\n')
        continue; // 丢弃输入行余下的字符
  }
  return ret_val;
}