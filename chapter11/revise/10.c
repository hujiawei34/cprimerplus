#include <stdio.h>
int strlen2(char *s) {
  int i = 0;
  while (*s++) {
    i++;
  }
  return i;
}
int main(void) {
  printf("%d", strlen2("abc"));
  return 0;
}