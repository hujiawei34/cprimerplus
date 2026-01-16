#include <stdio.h>
char *mystrncpy(char *dest, char *src, int n) {
  int i = 0;
  while (src[i] && i < n - 1) {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}
int main(void) {
  while (1) {
    const int SIZE = 10;
    char target[SIZE];
    char source[SIZE];
    printf("请输入一个字符串:");
    fgets(source, SIZE, stdin);
    mystrncpy(target, source, SIZE);
    printf("target: %s\n", target);
  }
  return 0;
}