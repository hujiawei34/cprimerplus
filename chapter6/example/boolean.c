/* trouble.c -- 误用=会导致无限循环 */
#include <stdio.h>
int main(void) {
  long num;
  long sum = 0L;
  int status;
  _Bool input_is_good;
  printf("Please enter an integer to be summed ");
  printf("(q to quit):");
  input_is_good = scanf("%ld", &num) == 1;
  while (input_is_good) {
    sum += num;
    printf("Please enter an integer to be summed (q to quit):");
    input_is_good = scanf("%ld", &num) == 1;
  }
  printf("Those integers sum to %ld.\n", sum);
  return 0;
}