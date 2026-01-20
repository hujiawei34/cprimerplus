#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFSIZE 4096
int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s \"str\" filename\n", argv[0]);
    return 1;
  }
  char *str = argv[1];
  char *filename = argv[2];
  FILE *fp;
  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", filename);
    return 1;
  }
  char line[BUFFSIZE];
  bool finded = false;
  while (fgets(line, BUFFSIZE, fp)) {
    char *find = strstr(line, str);
    if (find) {
      if (!finded)
        printf("find %s in %s:\n%s", str, filename, line);
      else
        printf("%s", line);
      finded = true;
    }
  }
  if (!finded)
    printf("can't find %s in %s\n", str, filename);
  return 0;
}