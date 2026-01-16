#include "my.h"
#include <stdio.h>
#include <string.h>
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