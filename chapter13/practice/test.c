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
}#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s sourc_filename target_filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *source_filename = argv[1], *target_filename = argv[2];
    FILE *fp_s, *fp_t;
    if ((fp_s = fopen(source_filename, "rb")) == NULL)
    {
        fprintf(stderr, "cannot read %s\n", source_filename);
        exit(EXIT_FAILURE);
    }
    if ((fp_t = fopen(target_filename, "wb")) == NULL)
    {
        fprintf(stderr, "can not write to %s\n", target_filename);
        exit(EXIT_FAILURE);
    }
    int BUFFSIZE = 4096;
    char buff[BUFFSIZE];
    int bytes;
    while ((bytes = fread(buff, sizeof(char), BUFFSIZE, fp_s)) > 0)
    {
        fwrite(buff, sizeof(char), bytes, fp_t);
    }
    fclose(fp_s);
    fclose(fp_t);

    return 0;
}