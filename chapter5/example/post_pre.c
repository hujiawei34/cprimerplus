/* post_pre.c -- 后缀和前缀递增运算符*/
#include <stdio.h>
int main(void) {
  int a = 1, b = 1;
  int a_post, pre_b ,q_pre,q_post;
  a_post = a++;
  pre_b = ++b;
  printf("a a_post     b pre_b\n");
  printf("%d %5d %5d %5d\n", a, a_post, b, pre_b);
  a=1,b=1;
  q_pre= 2*++a; // 先将a增加到2，再将2乘以2，结果为4
  q_post= 2*b++; // 先将b乘以2，结果为2，再将b增加到2
  printf("a q_pre b q_post\n");
  printf("%d %5d %5d %5d\n", a, q_pre, b, q_post);

  return 0;
}