#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFSIZE 4096
char *get_filename(char *filename, int n) {
  printf("Enter filename: ");
  fgets(filename, n, stdin);
  char *find = strchr(filename, '\n');
  if (find)
    *find = '\0';
  else
    while (getchar() != '\n')
      continue;
  return filename;
}
int main(int argc, char *argv[]) {
  char filename[128];
  get_filename(filename, 128);
  printf("You entered %s\n", filename);
  FILE *fp;
  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", filename);
    exit(EXIT_FAILURE);
  }
  int num;
  printf("enter a number(<0 to quit): ");
  while (scanf("%d", &num) == 1 && num >= 0) {
    if (feof(fp)) {
      fprintf(stderr, "number exceed %s's max position.\n", filename);
      continue;
    }
    printf("The line at %d position is: ", num);
    fseek(fp, num, SEEK_SET);
    char line[BUFFSIZE];
    fgets(line, BUFFSIZE, fp);
    char *find = strchr(line, '\n');
    if (find)
      *find = '\0';
    printf("[%s]", line);
    puts("");
    printf("enter a number(<0 to quit): ");
    rewind(fp);
  }
  return 0;
}