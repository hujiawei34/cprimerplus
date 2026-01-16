#include <ctype.h>
#include <stdio.h>
void get_word(char ar[], int n) {
  char prev = '\0';
  int i = 0;
  while (i < n) {
    char tmp = getchar();
    if (isblank(tmp) || tmp == '\n') {
      if (isblank(prev) || prev == '\n' || prev == '\0') {
      } else {
        ar[i] = '\0';
        break;
      }
    } else {
      ar[i++] = tmp;
    }
    prev = tmp;
  }
}
int main(void) {
  char str[10];
  get_word(str, 10);
  printf("%s", str);
  return 0;
}