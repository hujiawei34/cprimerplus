#include <stdio.h>
#include <string.h>
int main(void) {
  char food[] = "Yummy";
  char *ptr;

  ptr = food + strlen(food);
  while (--ptr >= food)
    puts(ptr);
  // y
  // my
  // mmy
  // ummy
  // Yummy
  return 0;
}