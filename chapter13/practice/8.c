#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NUM 10
#define FILE_NAME_LEN 100
void get_filelist(char *filelist[], int argc, char *argv[]) {
  for (int i = 2; i < argc; i++) {
    filelist[i - 2] = argv[i];
  }
}
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
void get_filelist_from_stdin(char *filelist[]) {
  printf("Enter file names (one per line, end with Ctrl-D):\n");

  char filename[FILE_NAME_LEN];
  int i = 0;
  while (i < MAX_FILE_NUM && s_gets(filename, FILE_NAME_LEN) != NULL) {
    filelist[i] = (char *)malloc(strlen(filename) + 1);
    if (filelist[i] != NULL) {
      strcpy(filelist[i], filename);
    }
    i++;
  }
}
int get_c_count(char *filename, char ch) {
  int count = 0;
  FILE *fp;
  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", filename);
    exit(EXIT_FAILURE);
  }
  char c;
  while ((c = getc(fp)) != EOF) {
    if (c == ch)
      count++;
  }
  fclose(fp);
  return count;
}
int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s 'char' [filename1] [filename1] ...\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  char ch = argv[1][0];
  char *filelist[MAX_FILE_NUM] = {NULL};
  if (argc > 2) {
    get_filelist(filelist, argc, argv);
  } else {
    get_filelist_from_stdin(filelist);
  }
  int sum = 0;
  for (int j = 0; j < MAX_FILE_NUM; j++) {
    if (filelist[j] == NULL)
      break;
    int count = get_c_count(filelist[j], ch);
    printf("file %s has %d '%c'\n", filelist[j], count, ch);
    sum += count;
  }
  return 0;
}