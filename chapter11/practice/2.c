#include <ctype.h>
#include <stdio.h>

void get_input(char ar[], int n) {
  for (int i = 0; i < n; i++) {
    ar[i] = getchar();
    if (isspace(ar[i]) || ar[i] == '\n') {
      ar[i] = '\0';
      break;
    }
  }
}
int main(void) {
  char str[5];
  get_input(str, 5);
  // puts(str);
  printf("%s", str);
  return 0;
}