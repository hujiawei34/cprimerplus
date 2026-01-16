/* put1.c -- 打印字符串，不添加\n*/
#include <stdio.h>
void put1(const char *string) {
  while (*string)
    putchar(*string++);
}
int put2(const char *string) {
  int count = 0;
  while (*string) {
    putchar(*string++);
    count++;
  }
  putchar('\n');
  return count;
}
int main(void) {
  put1("If I'd as much money");
  put1(" as I could spend,\n");
  printf("i count %d characters.\n",
         put2("i never would cry old chairs to mend."));
  return 0;
}