#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFSIZE 4096
int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  FILE *fp1, *fp2;
  char *fn1, *fn2;
  fn1 = argv[1];
  fn2 = argv[2];
  if ((fp1 = fopen(fn1, "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", fn1);
    exit(EXIT_FAILURE);
  }
  if ((fp2 = fopen(fn2, "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", fn2);
    exit(EXIT_FAILURE);
  }
  char line1[BUFFSIZE], line2[BUFFSIZE];
  bool file1_end = false;
  bool file2_end = false;
  while (1) {
    if (fgets(line1, BUFFSIZE, fp1) == NULL)
      file1_end = true;
    if (fgets(line2, BUFFSIZE, fp2) == NULL)
      file2_end = true;
    if (!file1_end)
      fputs(line1, stdout);
    if (!file2_end)
      fputs(line2, stdout);
    if (file1_end && file2_end)
      break;
  }
  puts("===================b===================");
  rewind(fp1);
  rewind(fp2);
  char ch = '\0';
  while (1) {
    for (int i = 0; (ch = getc(fp1)) != EOF && ch != '\n'; i++) {
      fputc(ch, stdout);
    }
    for (int i = 0; (ch = getc(fp2)) != EOF && ch != '\n'; i++) {
      fputc(ch, stdout);
    }
    fputc('\n', stdout);
    if (feof(fp1) && feof(fp2))
      break;
  }
  fclose(fp1);
  fclose(fp2);
  return 0;
}