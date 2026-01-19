// hidding.c --块中变量
#include <stdio.h>
int main(void) {
  int x = 30;

  printf("x in outer block is %d at %p\n", x, &x);
  {
    int x = 20;
    printf("x in inner block is %d at %p\n", x, &x);
  }
  
  printf("x in outer block is %d at %p\n", x, &x);
  while (x++ < 33) {
    int x = 100;
    x++;
    printf("x in while loop is %d at %p\n", x, &x);
  }
  printf("x in outer block is %d at %p\n", x, &x);
  return 0;
}