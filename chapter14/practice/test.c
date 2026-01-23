#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *s_gets_fp(char *s, int n, FILE *fp) {
  char *ret_val;
  int i = 0;
  ret_val = fgets(s, n, fp);
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
int main(void) {
  FILE *fp = fopen("books.txt", "r");
  char line[100];
  while (s_gets_fp(line, 100, fp) != NULL) {
    printf("line:%s\n", line);
  }
}