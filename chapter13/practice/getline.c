#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void use_getline() {
  printf("Enter filename:\n");
  char *filename;
  size_t bytes = 0;
  filename = malloc(4096);
  getline(&filename, &bytes, stdin);
  printf("You entered %s", filename);
  free(filename);
}
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
  // use_getline();
  // char *buffer = malloc(4096);
  // s_gets(buffer, 4096);
  // free(buffer);
  char filename[100];
  while (s_gets(filename, 100) != NULL) {
    printf("You entered %s\n", filename);
  }
  return 0;
}