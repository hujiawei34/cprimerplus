/* count.c -- 使用标准I/O*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
  int ch;
  FILE *fp;
  unsigned long count = 0;
  printf("Enter filename:");
  char file[100];
  scanf("%100s", file);
  if ((fp = fopen(file, "r")) == NULL)
  {
    fprintf(stderr, "can not read %s\n", file);
    exit(EXIT_FAILURE);
  }
  while ((ch = getc(fp)) != EOF)
  {
    putc(ch, stdout);
    // putchar(ch);
    count++;
  }
  fclose(fp);
  puts("");
  printf("File %s has %lu characters\n", file, count);
  return 0;
}