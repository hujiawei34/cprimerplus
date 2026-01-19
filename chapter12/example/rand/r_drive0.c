/* r_drive0.c -- 测试rand0()函数*/
#include <stdio.h>
extern unsigned int rand0(void);

int main(void) {
  int i;
  for (i = 0; i < 10; i++)
    printf("%d\n", rand0());
  return 0;
}