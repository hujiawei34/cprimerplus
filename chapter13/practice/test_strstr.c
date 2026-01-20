#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  char *str1 = "hello";
  char *str2 = "ll";
  char *find = strstr(str1, str2);
  if (find)
    printf("find %s in %s:\n[%s]\n", str2, str1, find);
  else
    printf("can't find %s in %s\n", str2, str1);
  return 0;
}