#include <stdio.h>
#include <stdlib.h>
#define BUFFSIZE 1024
int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  FILE *fp1, *fp2;
  if ((fp1 = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  if ((fp2 = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }
  int bytes;
  char line[BUFFSIZE];
  while ((bytes = fread(line, sizeof(char), BUFFSIZE, fp1)) > 0)
    fwrite(line, sizeof(char), bytes, fp2);
  fclose(fp1);
  fclose(fp2);

  return 0;
}