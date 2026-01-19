#include <stdio.h>
#include <stdlib.h>
int main(void) {
  printf("How many words do you wish to enter?");
  int w;
  scanf("%d", &w);
  printf("Enter %d words now:\n", w);
  char *p[w];
  for (int i = 0; i < w; i++) {
    char *pc; // char point ->a word
    pc = malloc(10 * sizeof(char));//如果没有这个，会有未初始化指针的问题，导致内存泄漏
    scanf("%s", pc);
    p[i] = pc;
  }
  printf("Here are your words:\n");
  for (int i = 0; i < w; i++) {
    puts(p[i]);
    free(p[i]);
  }
  return 0;
}