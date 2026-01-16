/* mod_str.c -- 修改字符串 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define LIMIT 81
void ToUpper(char *str) {
  while (*str) {
    *str = toupper(*str);
    str++;
  }
}
int PunctCount(const char *str) {
  int count = 0;
  while (*str) {
    if (ispunct(*str))
      count++;
    str++;
  }
  return count;
}
int main(void) {
  char line[LIMIT];
  char *find;

  puts("Please enter a line:");
  fgets(line, LIMIT, stdin);
  find = strchr(line, '\n');
  if (find)
    *find = '\0';
  ToUpper(line);
  printf("The line in uppercase is:\n%s\n", line);
  printf("The line contains %d punctuation characters.\n", PunctCount(line));
  return 0;
}