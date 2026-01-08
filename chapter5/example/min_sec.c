// min_sec.c -- 将秒数转换为分钟数和秒数
#include <stdio.h>
#define SEC_PER_MIN 60
int main(void) {
  int sec, min, left;
  printf("Convert seconds to minutes and seconds!\n");
  printf("Enter the number of seconds (<=0 to quit):\n");
  scanf("%d", &sec); // 读取秒数
  while (sec > 0) {
    min = sec / SEC_PER_MIN;
    left = sec % SEC_PER_MIN;
    printf("%d seconds = %d minutes, %d seconds.\n", sec, min, left);
    printf("Enter next number of seconds (<=0 to quit):\n");
    scanf("%d", &sec); // 读取秒数
  }
  printf("Done!\n");
  return 0;
}