#include <stdio.h>
int times;
int func(void) {
  extern int times;
  times++;
  return times;
}
int main(void) {
  for (int i = 0; i < 5; i++)
    printf("%d\n", func());
  return 0;
}