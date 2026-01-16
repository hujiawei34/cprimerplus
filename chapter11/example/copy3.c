#include <stdio.h>
#include <string.h>
#define SIZE 40
#define TARGETSIZE 7
#define LIM 5
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
int main(void) {
  char qwords[LIM][TARGETSIZE];
  char temp[SIZE];
  int i = 0;
  printf("Enter %d words beginning with q:\n", LIM);
  while (i < LIM && s_gets(temp, SIZE)) {
    if (temp[0] != 'q')
      printf("%s doesn't begin with q!\n", temp);
    else {
      strncpy(qwords[i], temp, TARGETSIZE - 1);
      qwords[i][TARGETSIZE - 1] = '\0';
      i++;
    }
  }
  printf("Here are the words:\n");
  for (i = 0; i < LIM; i++)
    printf("%s\n", qwords[i]);
  return 0;
}