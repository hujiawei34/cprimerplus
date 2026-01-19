/* local_stat.c -- 局部静态变量 */
#include <stdio.h>
void trystat(void);

int main(void) {
  int count;
  for (count = 1; count <= 3; count++) {
    printf("Here comes iteration %d\n", count);
    trystat();
  }
  return 0;
}
void trystat(void) {
  int fade = 1;
  static int stay = 1;// 静态变量的初始化在程序开始时进行，只执行一次，之所以放在函数中，是为了让这个变量只在这个函数可见
  printf("fade=%d,stay=%d\n", fade++, stay++);
}