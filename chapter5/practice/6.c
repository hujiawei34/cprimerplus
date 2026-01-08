/* addemup.c -- 几种常见的语句*/
#include <stdio.h>
int main(void) {
  int count, sum;

  count = 1;
  sum = 0;
  int days;

  printf("input days :");
  scanf("%d", &days);
  while (count < days + 1) {
    sum += count * count;
    count++;
  }

  printf("sum=%d\n", sum);

  return 0;
}