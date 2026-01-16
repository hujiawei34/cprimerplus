#include <ctype.h>
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
void set_lower(char *s) {
  while (*s) {
    *s = tolower(*s);
    s++;
  }
}
int main(void) {
    char str[SIZE];
    puts("Who is buried in Grant's tomb? ");
    s_gets(str, SIZE);
    set_lower(str);
    char answer[]=ANSWER;
    set_lower(answer);
    while (strcmp(str, answer)) {
      puts("No, that's wrong. Try again.");
      s_gets(str, SIZE);
      set_lower(str);
    }
    puts("That's right!");
  return 0;
}