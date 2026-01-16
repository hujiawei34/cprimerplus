/* scan_str.c -- 使用scanf()*/
#include <stdio.h>

int main(void) {
  char name1[11], name2[11];
  int count;
  puts("Please enter 2 names.");
  count = scanf("%5s %10s", name1, name2);
  printf("I read the %d names %s and %s.\n", count, name1, name2);
  return 0;
}