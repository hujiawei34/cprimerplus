/* reduceto.c --把文件压缩至原来的1/3! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40 // 新文件名长度
int main(int argc, char const *argv[]) {
  FILE *in, *out;
  int count = 0;
  if (argc < 2) {
    fprintf(stdout, "Usage: %s filename\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  if ((in = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  char newname[LEN];
  strncpy(newname, argv[1], LEN - 5);
  newname[LEN - 5] = '\0';
  strcat(newname, ".red");
  if ((out = fopen(newname, "w")) == NULL) {
    fprintf(stderr, "Can't create %s\n", newname);
    exit(EXIT_FAILURE);
  }
  int ch;
  while ((ch = getc(in)) != EOF) {
    if (count++ % 3 == 0)
      putc(ch, out);
  }
  if (fclose(in) != 0 || fclose(out) != 0) {
    fprintf(stderr, "Error in closing files\n");
    exit(EXIT_FAILURE);
  }

  return 0;
}