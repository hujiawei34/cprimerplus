/* fseek(fp,10L,SEEK_CUR) ---测试这个命令的含义*/
#include <stdio.h>
#include <stdlib.h>
int main(void) {
  FILE *fp;
  char ch;
  if ((fp = fopen("test.txt", "rb")) == NULL) {
    printf("test_error can't open test.txt\n");
    exit(EXIT_FAILURE);
  }
  printf("current at %ld\n", ftell(fp));
  fseek(fp, 5L, SEEK_CUR);
  printf("current at %ld\n", ftell(fp));
  ch = getc(fp);
  printf("%c\n", ch);
  printf("current at %ld\n", ftell(fp));
  fseek(fp, -2L, SEEK_CUR);
  printf("current at %ld\n", ftell(fp));
  ch = getc(fp);
  printf("%c\n", ch);
  fclose(fp);
  return 0;
}