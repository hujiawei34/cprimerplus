// zeno.c -- 求序列的和
#include <stdio.h>
int main(void) {
  int t_ct; // 项数
  double time, pow_of_2;
  int limit;

  printf("Enter the number of terms you want: ");
  scanf("%d", &limit);
  for (time = 0, pow_of_2 = 1.0, t_ct = 1; t_ct <= limit;
       t_ct++, pow_of_2 *= 2.0) {
    time += 1.0 / pow_of_2;
    printf("time=%f when terms=%d\n", time, t_ct);
  }
  return 0;
}