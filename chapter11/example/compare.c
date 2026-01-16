#include <stdio.h>
#include <string.h>
#define ANSWER "Grant"
#define SIZE 40
char *s_gets(char *s, int n) {
  char *ret_val;
  int i = 0;
  ret_val = fgets(s, n, stdin);
  if (ret_val) {
    char *find = strchr(s, '\n');
    if (find)
      *find = '\0';
    else
      while (getchar() != '\n')
        continue;
  }
  return ret_val;
}
int main(void) {
  char str[SIZE];
  printf("Who is buried in Grant's tomb? ");
  s_gets(str, SIZE);
  while (strcmp(str, ANSWER)) {
    printf("No, that's wrong. Try again. ");
    s_gets(str, SIZE);
  }
  printf("You are right!\n");
  return 0;
}